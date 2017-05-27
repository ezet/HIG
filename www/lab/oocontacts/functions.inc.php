<?php
define('REVERSE', 1);

function GetName(&$row, $reverse='0') {
	if ($reverse)
		return "{$row['lastname']}, {$row['firstname']}";
	else
		return "{$row['firstname']} {$row['lastname']}";
}

function GetCountry($cid) {
	global $dbh;
	$sql = 'SELECT country FROM countries WHERE id = '.$cid;
	$country = $dbh->query($sql, PDO::FETCH_ASSOC)->fetch();
	return $country['country'];
}

function PrintContacts(&$sql, $reverse='0') {
	global $dbh;
	echo '<ul>';
	foreach ($dbh->query($sql, PDO::FETCH_ASSOC) as $row)
		echo '<li class="contact"><a href="details.php?uid=' . $row['id'] . '">' . GetName($row, $reverse) . '</li>';
	echo '</ul>';
}


function updateContact () {
	global $dbh;
	$sql = 'UPDATE people SET firstname = ?, lastname = ?, address = ?, postalcode = ?, postal = ?, country = ? WHERE id = ?';
	$sth = $dbh->prepare($sql);
	$sth->execute(array ($_GET['firstname'], $_GET['lastname'], $_GET['address'], $_GET['postalcode'], $_GET['postal'], $_GET['country'], $_GET['uid']));
	echo $_GET['firstname'] . ' ' . $_GET['lastname'] . ' has been successfully updated.';
}

function isValidUid(&$error=array()) {
	global $dbh;
	$valid = true;
	// Checks for UID as parameter
	if (!isset($_GET['uid']) || empty($_GET['uid'])) {
		$error[] = 'Missing parameter UID';
		$valid = false;
	}
	// Checks if UID exists
	else {
		$sql = 'SELECT id FROM people WHERE id = ?';
		$sth = $dbh->prepare($sql);
		$sth->execute(array($_GET['uid']));
		if (!$sth->rowCount())
			$error[] = 'UID does not exist';
		$valid = false;
	}
	return $valid;
}

?>