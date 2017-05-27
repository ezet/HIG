<?php
require_once 'db.php';
if (isset ($_POST['deletecontactinfo'])) {
	$sql = 'SELECT uid FROM contactinfo WHERE id=:id';
	$sth = $db->prepare ($sql);
	$sth->bindParam (':id', $_POST['id']);
	$sth->execute ();
	$row = $sth->fetch();
	$uid = $row['uid'];
	$sth->closeCursor();
	$sql = 'DELETE FROM contactinfo WHERE id=:id';
	$sth = $db->prepare ($sql);
	$sth->bindParam (':id', $_POST['id']);
	$sth->execute ();
	$id = $uid;
	$updated = 'Kontaktinformasjon er slettet';
} else if (isset ($_POST['changecontactinfo'])) {
	$sql = 'SELECT uid FROM contactinfo WHERE id=:id';
	$sth = $db->prepare ($sql);
	$sth->bindParam (':id', $_POST['id']);
	$sth->execute ();
	$row = $sth->fetch();
	$uid = $row['uid'];
	$sth->closeCursor();
	$sql = 'UPDATE contactinfo SET contactinfo=:info, description=:description WHERE id=:id';
	$sth = $db->prepare ($sql);
	$sth->bindParam (':id', $_POST['id']);
	$sth->bindParam (':info', $_POST['info']);
	$sth->bindParam (':description', $_POST['description']);
	$sth->execute ();
	$id = $uid;
	$updated = 'Kontaktinformasjon er oppdatert';
} else if (isset ($_POST['contactChanged'])) {
	$sql = 'SELECT country FROM countries WHERE id=:id';
	$sql1 = 'SELECT poststed FROM postnr where postnr=:postnr';
	$sql2 = 'UPDATE people SET givenname=:givenname, surename=:surename, address1=:address1, address2=:address2, postalcode=:postalcode, postal=:postal, country=:country WHERE id=:id';
	$sth = $db->prepare ($sql);
	$sth->bindParam (':id', $_POST['country']);
	$sth->execute ();
	$row = $sth->fetch ();
	$sth->closeCursor ();
	if ($row['country']=='Norway') {
		$sth = $db->prepare ($sql1);
		$sth->bindParam (':postnr', $_POST['postcode']);
		$sth->execute ();
		$row = $sth->fetch ();
		if (!$row)
			$error = 'Feil postnummer, dette postnummeret finnes ikke!.';
		$sth->closeCursor ();
		$postal = $row['poststed'];
	} else	
		$postal = $_POST['postal'];
	$sth = $db->prepare ($sql2);
		$sth->bindParam (':givenname', $_POST['givenname']);
	$sth->bindParam (':surename', $_POST['surename']);
	$sth->bindParam (':address1', $_POST['address1']);
	$sth->bindParam (':address2', $_POST['address2']);
	$sth->bindParam (':postalcode', $_POST['postcode']);
	$sth->bindParam (':postal', $postal);
	$sth->bindParam (':country', $_POST['country']);
	$sth->bindParam (':id', $_POST['id']);
	$sth->execute ();
	$id = $_POST['id'];
	$updated = 'Informasjonen om kontakten er oppdatert';
} else if (isset ($_GET['id'])) {
	$id = $_GET['id'];
}

$sql = 'SELECT * FROM people WHERE id=:id';
$sth = $db->prepare ($sql);
$sth->bindParam (':id', $id);
$sth->execute ();
$row = $sth->fetch ();
$sth->closeCursor ();
$givenname = $row['givenname'];
$surename = $row['surename'];
$address1 = $row['address1'];
$address2 = $row['address2'];
$postalcode = $row['postalcode'];
$postal = $row['postal'];
$country = $row['country'];
$sql = 'SELECT * FROM countries where id=:id';
$sth = $db->prepare ($sql);
$sth->bindParam (':id', $country);
$sth->execute ();
$row = $sth->fetch ();
$sth->closeCursor ();
$country = $row['country'];

?><!DOCTYPE html>
<html>
<head>
<title>Redigere en kontakt</title>
<link rel="stylesheet" type="text/css" href="styles.css"/>
<script type="text/javascript">
function addContantinfo(id) {
	window.open ("addcontactinfo.php?id="+id, "newcontactinfo", "width=500,height=400");
}
</script>
</head>
<body>
<a href="index.html">Tilbake til adresseboken</a>
<h1 style="padding-top: 0px; margin-top: 0px;">Redigere en kontakt</h1>
<?php
if (isset ($updated))
  echo "<h2>$updated</h2>";
?>
<form method="post" action="edit.php">
<input type="hidden" name="id" value="<?php echo $id; ?>"/>
<label for="name">Navn</label><input type="text" name="givenname" value="<?php echo $givenname; ?>"/> <input type="text" name="surename" value="<?php echo $surename; ?>"/><br/>
<label for="address1">Adresse</label><input type="text" name="address1" value="<?php echo $address1; ?>"/><br/>
<label for="address2"> &nbsp;</label><input type="text" name="address2" value="<?php echo $address2; ?>"/><br/>
<label for="postcode">Postnr</label><input type="text" name="postcode" value="<?php echo $postalcode; ?>"/><br/>
<label for="postal">Poststed</label><input type="text" name="postal" value="<?php echo $postal; ?>"/><br/>
<label for="country">Land</label><select size="1" name="country">
<?php
$res = $db->query ('SELECT * FROM countries ORDER BY country');
while ($row = $res->fetch()) {
	echo '<option ';
		if ($country==$row['country'])
			echo 'selected ';
	echo "value='{$row['id']}'>{$row['country']}</option><br/>\n";
}
?></select><br/>
<input type="submit" name="contactChanged" value="Lagre endringer"/>
</form>
<h2>Kontaktinformasjon</h2>
<?php
$sql = 'SELECT * FROM contactinfo WHERE uid=:uid ORDER BY type, description';
$sth = $db->prepare ($sql);
$sth->bindParam (':uid', $id);
$sth->execute ();
$type = '';
while ($row = $sth->fetch()) {
	if ($row['type']!=$type)
		echo "<h3>{$row['type']}</h3>";
	$type = $row['type'];
	echo "<ul><li><form method='post' action='edit.php'><input type='hidden' name='id' value='{$row['id']}'/><input type='text' name='info' value='{$row['contactinfo']}'/> (<input type='text' name='description' value='{$row['description']}'/>) <input type='submit' name='changecontactinfo' value='Oppdater' title='Oppdater kontaktinformasjon'/> <input type='submit' name='deletecontactinfo' title='Slett denne kontaktinformasjonen' value='Slett'/></form></li></ul>\n";
}
?>
<a href="javascript:addContantinfo(<?php echo $id; ?>);">Legg til kontaktinformasjon</a>
</body>
</html>