<?php

function newContact () {
	global $dbh;
	$sql = 'INSERT INTO people (firstname, lastname, address, postalcode, postal, country) values (?, ?, ?, ?, ?, ?)';
	$sth = $dbh->prepare($sql);
	$sth->execute(array ($_GET['firstname'], $_GET['lastname'], $_GET['address'], $_GET['postalcode'], $_GET['postal'], $_GET['country']));
	echo $_GET['firstname'] . ' ' . $_GET['lastname'] . ' has been successfully added to your contacts.';
}

if (isset($_GET['action']))
switch ($_GET['action']) {

// ADD NEW CONTACT
	case 'add':
		if (isset($_GET['firstname'])) {
			if (empty($_GET['firstname']) || empty($_GET['postalcode'])) {
				echo '<span class="error">Firstname and postalcode cannot be empty.</span>';
			}
			else {
				$sql = "SELECT id FROM people WHERE firstname = '{$_GET['firstname']}' AND lastname = '{$_GET['lastname']}'";
				if ($dbh->query($sql)->fetch()) {
					echo $_GET['firstname'] . ' ' . $_GET['lastname'] . ' already exists in the database.';
				}
				else {
					$country = $dbh->query('SELECT id FROM countries WHERE country="Norway"')->fetch();
					if ($_GET['country'] == $country['id']) {
						$sql = "SELECT postal FROM postalcodes WHERE postalcode = '{$_GET['postalcode']}'";
						if ($row = $dbh->query($sql)->fetch()) {
							$_GET['postal'] = $row['postal'];
							newContact();
							break;
						}
						else { // ENDIF postalcode
							echo 'Invalid postalcode.';
						}
					} else { // ENDIF norwegian
					newContact();
					break;
					}
				} // ENDIF contact exists
			} // ENDIF empty fields
		}
	case 'new':
		//$ipinfo = file ("http://api.hostip.info/get_html.php?ip={$_SERVER['REMOTE_ADDR']}");
		//$geo = strtolower(substr($ipinfo[0], 9, (strpos($ipinfo[0], '(', 10) - 10)));
		//$showcontacts = 0;
		$geo = 'norway';
		?>
		<h3>Add a new contact</h3>
		<form method="GET">	
		<input name="page" value="contacts" type="hidden"/>
		<input name="action" value="add" type="hidden"/>
		<label for="firstname">Firstname</label><input type="text" name="firstname" value="<?php if (isset($_GET['firstname'])) echo $_GET['firstname'] ?>" required="required"/><br/>
		<label for="lastname">Lastname</label><input type="text" name="lastname" value="<?php if (isset($_GET['lastname'])) echo $_GET['lastname'] ?>"required="required"/><br/>
		<label for="address">Address</label><input type="text" name="address" value="<?php if (isset($_GET['address'])) echo $_GET['address'] ?>"required="required"/><br/>
		<label for="postalcode">Postalcode</label><input type="number" name="postalcode" value="<?php if (isset($_GET['postalcode'])) echo $_GET['postalcode'] ?>" min="1" max="9999" required="required"/><br/>
		<label for="postal">Postal </label><input type="text" name="postal" value="<?php if (isset($_GET['postal'])) echo $_GET['postal'] ?>" placeholder="...if outside of Norway"required="required"/><br/>
		<label for="country">Country</label>
		<select name="country">
		<?php
		foreach ($dbh->query('SELECT * FROM countries') as $row) {
			echo '<option value="' . $row['id'] . '"';
			if (isset($_GET['country']) && $_GET['country'] == $row['id']) echo ' selected';
			if (!isset($_GET['country']) && strtolower($row['country']) == $geo) echo ' selected';
			echo '>' . $row['country'] . '</option>' . "\n";
		}
		?>
		</select><br/>
		<input type="submit" value="Add"/>
		</form>
		<?php break;
		
// DELETE CONTACT
	case 'delete':
		$sql = "DELETE FROM contactinfo WHERE uid = {$_GET['uid']}";
		$dbh->exec($sql);
		$sql = "DELETE FROM people WHERE id = {$_GET['uid']}";
		if ($dbh->exec($sql))
			echo 'Contact successfully deleted.';
		else
			echo 'Could not delete contact.';
		break;
	
	default: continue;
}

echo '<h3>My contacts</h3>';
$sql = 'SELECT id, firstname, lastname FROM people ORDER BY lastname LIMIT 30';
foreach ($dbh->query($sql) as $row) {
	echo '<a href="?page=details&uid='.$row['id'].'">';
	echo $row['lastname'] . ', ' . $row['firstname'] . '</a><br/>';
}

?>