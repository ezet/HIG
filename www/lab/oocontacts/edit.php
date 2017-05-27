<?php
require_once('config.inc.php');

$error = array();
$update;
$input = array ('firstname', 'lastname', 'address', 'postalcode');
isValidUid($error);


// SUBMITTED EDIT
if (isset($_POST['action']) && $_POST['action'] == 'submitedit') {
	// Checking for missing fields
	foreach ($input as $field)
		if (!isset($_POST[$field]) || empty($_POST[$field]))
			$error[]= 'Missing input field: '. ucfirst($field);

	// Checking for duplicate entry
	$sql = 'SELECT id FROM people WHERE firstname = ? AND lastname = ?';
	$sth = $dbh->prepare($sql);
	$sth->execute(array($_POST['firstname'], $_POST['lastname']));
	$row = $sth->fetch();
	if ($row && $row['id'] != $_GET['uid'])
		$error[] = $_POST['firstname'] . ' ' . $_POST['lastname'] . ' already exists in the database';
		
	// If Norwegian
	$sql = 'SELECT id FROM countries WHERE country="Norway"';
	$country = $dbh->query($sql)->fetch();
	if ($_POST['country'] == $country['id']) {
		// Check for legit postalcode
		$sql = "SELECT postal FROM postalcodes WHERE postalcode = '{$_POST['postalcode']}'";
		if ($dbh->query($sql)->fetch())
			$_POST['postal'] = $row['postal'];
		else
			$error[] = $_POST['postalcode'] . ' is not a legit postalcode';
	}
	// if errors, print them
	if ($error) {
	foreach ($error as $errmsg)
		echo '<span class="error">'.$errmsg.'</span><br/>';
	} else {
	// complete update
	$sql = 'UPDATE people SET firstname = ?, lastname = ?, address = ?, postalcode = ?, postal = ?, country = ? WHERE id = ?';
	$sth = $dbh->prepare($sql);
	$sth->execute(array ($_POST['firstname'], $_POST['lastname'], $_POST['address'], $_POST['postalcode'], $_POST['postal'], $_POST['country'], $_POST['uid']));
	$update = 'Updating details for '.$_POST['firstname'] . ' ' . $_POST['lastname'];
	}
} // endif isset



// BEGIN HTML
require_once('header.php');
$action = isset($_GET['action']) ? $_GET['action'] : 'default';
switch ($action) {
// EDIT CONTACT
	default:
	// if errors
	if ($error) {
		echo 'Cannot edit contact: ';
		foreach ($error as $errmsg)
			echo $errmsg;
	} else {
	// else edit
	$sql = 'SELECT * FROM people WHERE id = ?';
	$sth = $dbh->prepare($sql);
	$sth->execute(array($_GET['uid']));
	$row = $sth->fetch();
	$sth->closeCursor();
	?>
	<h3>Edit contact</h3>
	<form method="POST">
		<input name="page" value="details" type="hidden"/>
		<input name="action" value="submitedit" type="hidden"/>
		<input name="uid" value="<?php  echo $_GET['uid'] ?>" type="hidden"/>
		<label for="firstname">Firstname</label><input name="firstname" value="<?php echo $row['firstname'] ?>" type="text" required="required"/><br/>
		<label for="lastname">Lastname</label><input name="lastname" value="<?php echo $row['lastname'] ?>" type="text" required="required"/><br/>
		<label for="address">Address</label><input name="address" value="<?php echo $row['address'] ?>" type="text" required="required"/><br/>
		<label for="postalcode">Postalcode</label><input name="postalcode" value="<?php echo $row['postalcode'] ?>" type="number" min="1" max="9999" required="required"/><br/>
		<label for="postal">Postal </label><input name="postal" value="<?php echo $row['postal'] ?>" type="text"  placeholder="...if outside of Norway"required="required"/><br/>
		<label for="country">Country</label><select name="country">
		<?php
		foreach ($dbh->query('SELECT * FROM countries') as $country) {
			echo '<option value="', $country['id'], '"';
			if ($country['id'] == $row['country']) echo ' selected';
			echo '>', $country['country'], "</option>\n";
		}
		?>
		</select><br/>
		<input type="submit" value="Save"/>
	</form>
	<?php
	}
}
require_once('footer.php'); ?>