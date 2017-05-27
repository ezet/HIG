<?php
require_once 'db.php';
if (isset ($_GET['id'])) {
	$sql = 'SELECT * FROM people WHERE id=:id';
	$sth = $db->prepare ($sql);
	$sth->bindParam (':id', $_GET['id']);
	$sth->execute ();
	$row = $sth->fetch ();
	$sth->closeCursor ();
	$name = $row['givenname'].' '.$row['surename'];
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
}
?><!DOCTYPE html>
<html>
<head>
<title>Detaljer for kontakt</title>
<link rel="stylesheet" type="text/css" href="styles.css"/>
<script type="text/javascript">
function addContantinfo(id) {
	window.open ("addcontactinfo.php?id="+id, "newcontactinfo", "width=500,height=400");
}
</script>
</head>
<body>
<a href="index.html">Tilbake til adresseboken</a>
<h1 style="padding-top: 0px; margin-top: 0px;">Detaljer for kontakt</h1>
<a href="edit.php?id=<?php echo $_GET['id']; ?>"><img src="EditBook.gif" style="border:0px"> Redigere kontakt</a><br/>
<label for="name">Navn</label><?php echo $name; ?><br/>
<label for="address1">Adresse</label><?php echo $address1; ?><br/>
<label for="address2"> &nbsp;</label><?php echo $address2; ?><br/>
<label for="postcode">Postnr</label><?php echo $postalcode; ?><br/>
<label for="postal">Poststed</label><?php echo $postal; ?><br/>
<label for="country">Land</label><?php echo $country; ?>
<h2>Kontaktinformasjon</h2>
<?php
$sql = 'SELECT * FROM contactinfo WHERE uid=:uid ORDER BY type, description';
$sth = $db->prepare ($sql);
$sth->bindParam (':uid', $_GET['id']);
$sth->execute ();
$type = '';
while ($row = $sth->fetch()) {
	if ($row['type']!=$type)
		echo "<h3>{$row['type']}</h3>";
	$type = $row['type'];
	echo "<ul><li>{$row['contactinfo']} ({$row['description']})</li></ul>\n";
}
?>
<a href="javascript:addContantinfo(<?php echo $_GET['id']; ?>);">Legg til kontaktinformasjon</a>
</body>
</html>