<?php
require_once('config.inc.php');

$editid = false;
$complete = false;
$error = array();
$errmsg = 'Could not retrieve contact from database: ';
isValidUid($error);

// Performing delete contact
if (isset($_GET['action']) && $_GET['action'] == 'delete') {
	$errmsg = 'Could not delete contact: ';
	if (!$error) {
		$sql = 'DELETE FROM contactinfo WHERE uid = ?';
		$sth = $dbh->prepare($sql);
		$sth->execute(array($_GET['uid']));
		$sql = 'DELETE FROM people WHERE id = ?';
		$sth = $dbh->prepare($sql);
		$sth->execute(array($_GET['uid']));
		$deleted = 'Deleting contact...done.';
	}
}

// Performing deleteinfo
if (isset($_GET['action']) && $_GET['action'] == 'deleteinfo') {
	$errmsg = 'Could not delete info: ';
	$sql = 'SELECT id FROM contactinfo WHERE id = ?';
	$sth = $dbh->prepare($sql);
	$sth->execute(array($_GET['id']));
	if (!$sth->fetch())
		$error[] = 'ID does not exist.';
	if (!$error) {
		$sql = 'DELETE FROM contactinfo WHERE id = ?';
		$sth = $dbh->prepare($sql);
		$sth->execute(array($_GET['id']));
		$complete = 'Deleting contactinfo...done.';
	}
}

// Performing edit
if (isset($_POST['submit']) && $_POST['submit'] == 'editinfo') {
	$errmsg = 'Could not edit info: ';
	$sql = 'SELECT id FROM contactinfo WHERE id = ?';
	$sth = $dbh->prepare($sql);
	$sth->execute(array($_POST['id']));
	if (!$sth->fetch())
		$error[] = 'ID does not exist.';
	if (!isset($_POST['contactinfo']) || empty($_POST['contactinfo']))
		$error[] = 'Missing input field: Contact information';
	if (!isset($_POST['type']) || empty($_POST['type']))
		$error[] = 'Missing input field: Type';
	if (!$error) {
		$sql = 'UPDATE contactinfo type=? contactinfo=?, description=? WHERE id=?';
		$sth = $dbh->prepare($sql);
		$sth->execute(array ($_POST['type'], $_POST['contactinfo'], $_POST['description'], $_POST['id']));
		$complete = 'Saving changes...done.';
	}
}

// Preparing edit
if (isset($_GET['action']) && $_GET['action'] == 'editinfo') {
	$errmsg = 'Could not edit info: ';
	$sql = 'SELECT id FROM contactinfo WHERE id = ?';
	$sth = $dbh->prepare($sql);
	$sth->execute(array($_GET['id']));
	if (!$sth->fetch())
		$error[] = 'ID does not exist.';
	if (!$error)
		$editid = $_GET['id'];
		$sql = 'SELECT * FROM contactinfo WHERE id = ?';
		$sth = $dbh->prepare($sql);
		$sth->execute(array($editid));	
		$editrow = $sth->fetch();
}


	
	
// BEGIN HTML
require_once('header.php');
// if errors, print them
if (isset($complete))
	echo $complete;	
if (isset($deleted))
	echo $deleted;
else if ($error) {
	echo $errmsg;
	foreach ($error as $err)
		echo $err;
} else {
	// PrintName by ID
	$uid = $_GET['uid'];
	$sql = 'SELECT * FROM people WHERE id = '.$uid;
	$row = $dbh->query($sql, PDO::FETCH_ASSOC)->fetch();
	echo '<h3>Details for '.GetName($row).'</h3>';

	// PrintDetails by ID
	echo '<ul class="details">';
	foreach ($row as $key=>$value) {
		if ($key == 'id') continue;
		if ($key == 'country') $value = GetCountry($value);
		echo '<li>'.ucfirst($key).': '. $value.'</li>';
	}
	echo '</ul>';

	// Get enums
	$sql = 'SHOW COLUMNS FROM contactinfo LIKE "type"';
	$row = $dbh->query($sql)->fetch(PDO::FETCH_ASSOC);
	$enums2 = array();
	preg_match_all("/'(.*?)'/", $row['Type'], $enums);
	
	// PrintContactInfo by ID
	$sql = 'SELECT * FROM contactinfo WHERE uid = ?';
	$sth = $dbh->prepare($sql);
	$sth->execute(array($_GET['uid']));
	$result = $sth->fetchAll();
	$sth->closeCursor();
	
	foreach ($enums[1] as $enum) {
		echo '<h4>', ucfirst($enum), ':</h4><ul>';
		foreach ($result as $info)
				if ($info['type'] == $enum)
					if ($info['id'] == $editid) {
						?>
						<form method="POST" action="<?php echo $_SERVER['PHP_SELF'], '?uid=', $_GET['uid'] ?>">
						<select name="type">
						<?php
						$sql = 'SHOW COLUMNS FROM contactinfo LIKE "type"';
						$res = $dbh->query($sql)->fetch();
						preg_match_all("/'(.*?)'/", $res['Type'], $enums);
						foreach ($enums[1] as $value) {
							echo '<option value="', $value, '"';
							if ($value == $editrow['type']) echo ' selected ';
							echo '">', $value, '</option>';
						} ?>
						</select>
						<input name="contactinfo" value="<?php echo $editrow['contactinfo'] ?>" type="text"/>
						<input name="description" value="<?php echo $editrow['description'] ?>" type="text"/>
						<input name="submit" value="editinfo" type="hidden"/>
						<input name="id" value="<?php echo $editid ?>" type="hidden"/>
						<input type="submit" value="Save"/>
						</form>
					<?php
					} else {
						echo '<li>', $info['contactinfo'], ' ( ', $info['description'],
						' ) <a href=details.php?action=editinfo&id=', $info['id'], '&uid=', $_GET['uid'], '>edit</a>',
						' <a href=details.php?action=deleteinfo&id=', $info['id'], '&uid=', $_GET['uid'], '>delete</a></li>';
					}
		echo '</ul>';
	}
}

require_once('footer.php');
?>