<?php

function updateContact () {
	global $dbh;
	$sql = 'UPDATE people SET firstname = ?, lastname = ?, address = ?, postalcode = ?, postal = ?, country = ? WHERE id = ?';
	$sth = $dbh->prepare($sql);
	$sth->execute(array ($_GET['firstname'], $_GET['lastname'], $_GET['address'], $_GET['postalcode'], $_GET['postal'], $_GET['country'], $_GET['uid']));
	echo $_GET['firstname'] . ' ' . $_GET['lastname'] . ' has been successfully updated.';
}

if (isset($_GET['action']))
switch ($_GET['action']) {

// EDIT CONTACT
	case 'edit':
		if (isset($_GET['firstname']) && isset($_GET['postalcode']))
			if (empty($_GET['firstname']) || empty($_GET['postalcode']))
				echo 'Firstname and postalcode cannot be empty.';
			else {
				$country = $dbh->query('SELECT id FROM countries WHERE country="Norway"')->fetch();
				if ($_GET['country'] == $country['id']) {
					$sql = "SELECT postal FROM postalcodes WHERE postalcode = '{$_GET['postalcode']}'";
					if ($row = $dbh->query($sql)->fetch()) {
						$_GET['postal'] = $row['postal'];
						updateContact();
					}
					else { // ENDIF postalcode
						echo 'Invalid postalcode.';
					}
				} else { // ENDIF norwegian
				updateContact();
				}
			}
	$sql = "SELECT * FROM people WHERE id = {$_GET['uid']}";
	$row = $dbh->query($sql)->fetch();
	?>
	<h3>Edit contact</h3>
	<form method="GET">
		<input name="page" value="details" type="hidden"/>
		<input name="action" value="edit" type="hidden"/>
		<input type="hidden" name="uid" value="<?php  echo $_GET['uid'] ?>"/>
		<label for="firstname">Firstname</label><input name="firstname" value="<?php echo $row['firstname'] ?>" type="text" required="required"/><br/>
		<label for="lastname">Lastname</label><input name="lastname" value="<?php echo $row['lastname'] ?>" type="text" required="required"/><br/>
		<label for="address">Address</label><input name="address" value="<?php echo $row['address'] ?>" type="text" required="required"/><br/>
		<label for="postalcode">Postalcode</label><input name="postalcode" value="<?php echo $row['postalcode'] ?>" type="number" min="1" max="9999" required="required"/><br/>
		<label for="postal">Postal </label><input name="postal" value="<?php echo $row['postal'] ?>" type="text"  placeholder="...if outside of Norway"required="required"/><br/>
		<label for="country">Country</label><select name="country">
		<?php
		foreach ($dbh->query('SELECT * FROM countries') as $country) {
			echo '<option value="' . $country['id'] . '"';
			if ($country['id'] == $row['country']) echo ' selected';
			echo '>' . $country['country'] . '</option>' . "\n";
		}
		?>
		</select><br/>
		<input type="submit" value="Save"/>
		</form>
	<?php break;

// ADD NEW CONTACT INFORMATION
	case 'addinfo':
		if (isset($_GET['contactinfo']) && !empty($_GET['contactinfo'])) {
			$sql = ('INSERT INTO contactinfo (uid, type, contactinfo, description) values (?, ?, ?, ?);');
			$sth = $dbh->prepare($sql);
			$sth->execute(array ($_GET['uid'], $_GET['type'], $_GET['contactinfo'], $_GET['description']));
			echo '<p>Contact information has been added.</p>';
		} ?>
		<h4>Add new information</h4>
		<form method="GET" action="<?php echo $_SERVER['PHP_SELF'] ?>">
		<input name="page" value="details" type="hidden"/>
		<input name="action" value="addinfo" type="hidden"/>
		<input name="uid" value="<?php  echo $_GET['uid'] ?>" type="hidden"/>
		<label for="type">Type</label><select name="type">
		<?php
		$sql = 'SHOW COLUMNS FROM contactinfo LIKE "type"';
		$result = $dbh->query($sql)->fetch();
		preg_match_all("/'(.*?)'/", $result['Type'], $enums);
		foreach ($enums[1] as $value)
			echo '<option value="'. $value . '">' . $value . '</option>';
		?>
		</select><br/>
		<label for="contactinfo">Contact information</label><input name="contactinfo" type="text" placeholder="contact information"/><br/>
		<label for="description">Descripion</label><input name="description" type="text" placeholder="description"/><br/>
		<input type="submit" value="Submit"/>
		</form>
		<?php break;

// EDIT CONTACT INFORMATION
	case 'editinfo':
		$sql = 'SELECT * FROM contactinfo WHERE uid = ' . $_GET['uid'];
		$row = $dbh->query($sql)->fetch();
		?>
		<h4>Edit contact information</h4>
		<form method="GET">
		<input name="page" value="details" type="hidden"/>
		<input name="action" value="editinfo" type="hidden"/>
		<input name="uid" value="<?php  echo $_GET['uid'] ?>" type="hidden"/>
		<label for="type">Type</label><select name="type">
		<?php
		$sql = 'SHOW COLUMNS FROM contactinfo LIKE "type"';
		$result = $dbh->query($sql)->fetch();
		preg_match_all("/'(.*?)'/", $result['Type'], $enums);
		foreach ($enums[1] as $value) {
			echo '<option value="'. $value . '"';
			if ($value == $row['type']) echo ' selected';
			echo '>' . $value . '</option>';
		}
		?>
		</select><br/>
		<label for="contactinfo">Contact information</label><input name="contactinfo" value="<?php echo $row['contactinfo'] ?>" type="text" placeholder="contact information"/><br/>
		<label for="description">Descripion</label><input name="description" value="<?php echo $row['description'] ?>" type="text" placeholder="description"/><br/>
		<input type="submit" value="Save"/>
		</form>
		<?php break;
	
// DELETE CONTACT INFORMATION
	case 'deleteinfo':
		$sql = "DELETE FROM contactinfo WHERE id = {$_GET['id']}";
		if ($dbh->exec($sql))
			echo 'Contact information has been successfully deleted.';
		else
			echo 'An error has occured, could not delete contact information.';
		break;
		
	default: continue;
}

// SHOW BASIC INFORMATION
$sql = "SELECT firstname, lastname FROM people WHERE id={$_GET['uid']}";
$name = $dbh->query($sql)->fetch();
echo "<h3>Contact information for {$name['firstname']} {$name['lastname']}:</h3>";
$sql = "SELECT address, postalcode, postal, country FROM people WHERE id={$_GET['uid']}";
foreach ($dbh->query($sql, PDO::FETCH_ASSOC) as $row)
	foreach ($row as $key=>$value)
		if ($key == 'country') {
			$country = $dbh->query("SELECT country FROM countries WHERE $value = id")->fetch();
			echo ucfirst($key) . ': ' . $country['country'] . '<br/>';
		}
		else
			echo ucfirst($key) . ': ' . $value . '<br/>';
echo '<br/>';
		
// SHOW DETAILED INFORMATION
$sql = "SELECT id, type, contactinfo, description FROM contactinfo WHERE uid={$_GET['uid']}";
foreach ($dbh->query($sql, PDO::FETCH_ASSOC) as $row) {
	foreach ($row as $key=>$value) {
		if ($key == 'id') continue;
		echo ucfirst($key) . ': ' . $value . '<br/>';
	}
	echo "<a href='index.php?page=details&action=editinfo&uid={$_GET['uid']}&id={$row['id']}'/>edit</a>
		<a href='index.php?page=details&action=deleteinfo&uid={$_GET['uid']}&id={$row['id']}'/>delete</a>";
	echo '<br/><br/>';	
}
?>