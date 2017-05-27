<?php
require_once('config.inc.php');
require_once('geoplugin.class.php');
$geoplugin = new geoPlugin();
$geoplugin->locate();
echo $geoplugin->countryName;

$error = array();
$input = array ('firstname', 'lastname', 'address', 'postalcode');
if (isset($_POST['action']) && $_POST['action'] == 'submitadd') {

	// Checking for missing fields
	foreach ($input as $field)
		if (!isset($_POST[$field]) || empty($_POST[$field]))
			$error[]= 'Missing input field: '. ucfirst($field);
	
	// Checking for duplicate entry
	$sql = 'SELECT id FROM people WHERE firstname = "'.$_POST['firstname'].'" AND lastname = "'.$_POST['lastname'].'"';
	if ($dbh->query($sql)->fetch())
		$error[] = $_POST['firstname'] . ' ' . $_POST['lastname'] . ' already exists in the database';
		
	// if Norwegian
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
	} 	else {
	// else complete insertion
		$sql = 'REPLACE INTO people (firstname, lastname, address, postalcode, postal, country) values (?, ?, ?, ?, ?, ?)';
		$sth = $dbh->prepare($sql);
		$sth->execute(array ($_POST['firstname'], $_POST['lastname'], $_POST['address'], $_POST['postalcode'], $_POST['postal'], $_POST['country']));
		$row = $dbh->query('SELECT LAST_INSERT_ID() AS id')->fetch();
		$uid = $row['id'];
		header ('location: details.php?uid='.$uid);
	}
}

// BEGIN HTML
require_once('header.php'); ?>
<h3>Add a new contact</h3>
<form method="POST">
<input name="action" value="submitadd" type="hidden"/>
<label for="firstname">Firstname</label><input type="text" name="firstname" value="<?php if (isset($_POST['firstname'])) echo $_POST['firstname'] ?>" required="required"/><br/>
<label for="lastname">Lastname</label><input type="text" name="lastname" value="<?php if (isset($_POST['lastname'])) echo $_POST['lastname'] ?>"required="required"/><br/>
<label for="address">Address</label><input type="text" name="address" value="<?php if (isset($_POST['address'])) echo $_POST['address'] ?>"required="required"/><br/>
<label for="postalcode">Postalcode</label><input type="number" name="postalcode" value="<?php if (isset($_POST['postalcode'])) echo $_POST['postalcode'] ?>" min="1" max="9999" required="required"/><br/>
<label for="postal">Postal </label><input type="text" name="postal" value="<?php if (isset($_POST['postal'])) echo $_POST['postal'] ?>" placeholder="...if outside of Norway"required="required"/><br/>
<label for="country">Country</label>
<select name="country">
<?php
foreach ($dbh->query('SELECT * FROM countries') as $row) {
	echo '<option value="' . $row['id'] . '"';
	if (isset($_POST['country']) && $_POST['country'] == $row['id']) echo ' selected';
	if ((!isset($_POST['country']) || empty($_POST['country'])) && strtolower($row['country']) == $geoplugin->countryName) echo ' selected';
	echo '>' . $row['country'] . '</option>' . "\n";
}
?>
</select><br/>
<input type="submit" value="Add"/>
</form>
<?php require_once('footer.php'); ?>