<?php
require_once('geoplugin.class.php');
$geoplugin = new geoPlugin();
$geoplugin->locate();
 
echo "Geolocation results for {$geoplugin->ip}: <br />\n".
		 "Country Name: {$geoplugin->countryName} <br />\n";

require_once 'db.php';
$error = false;
if (isset ($_POST['givenname'])) {
	$sql = 'SELECT country FROM countries WHERE id=:id';
	$sql1 = 'SELECT poststed FROM postnr where postnr=:postnr';
	$sql2 = 'INSERT INTO people (givenname, surename, address1, address2, postalcode, postal, country) VALUES (:givenname, :surename, :address1, :address2, :postalcode, :postal, :country)';
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
	$res = $sth->execute ();
	$res = $db->query ('SELECT LAST_INSERT_ID() as id');
	$row = $res->fetch();
	$id = $row['id'];
	if ($res < 1)
		$error = 'Kunne ikke sette inn data i databasen!.';
	if (!$error) {
		header ("location: details.php?id=".$id);
		exit ();
	}
}
?><!DOCTYPE html>
<html>
<head>
<title>Opprett kontakt</title>
<link rel="stylesheet" type="text/css" href="styles.css"/>
<script type="text/javascript" src="yqlgeo.js"></script>
<script type="text/javascript">
function position() {
	yqlgeo.get('visitor',function(o){
		if(o.error){
			alert('No location found for user :('); // some IPs are not in the DB :(
		} else {
			alert(o.place.name + ',' + o.place.country.content +  
						' (' + o.place.centroid.latitude + ',' +
									o.place.centroid.longitude + ')'
						);
		}
	});
}
</script>
</head>
<body onload="position();">
<h1>Opprett ny kontakt</h1>
<?php
if ($error) 
  echo "<h2 class='error'>$error</h2>\n";
?>
<form method="post" action="new.php">
<label for="givenname">Fornavn</label><input type="text" name="givenname" <?php if (isset($_POST['givenname'])) echo "value='{$_POST['givenname']}'"; ?>/><br/>
<label for="surename">Etternavn</label><input type="text" name="surename" <?php if (isset($_POST['surename'])) echo "value='{$_POST['surename']}'"; ?>/><br/>
<label for="address1">Adresse</label><input type="text" name="address1" <?php if (isset($_POST['address1'])) echo "value='{$_POST['address1']}'"; ?>/><br/>
<label for="address2"> &nbsp;</label><input type="text" name="address2" <?php if (isset($_POST['address2'])) echo "value='{$_POST['address2']}'"; ?>/><br/>
<label for="postcode">Postnr</label><input type="text" name="postcode" <?php if (isset($_POST['postcode'])) echo "value='{$_POST['postcode']}'"; ?>/></br>
<label for="postal">Poststed<br/><span class="small">Trengs ikke for norske adresser</span></label><input type="text" name="postal" <?php if (isset($_POST['postal'])) echo "value='{$_POST['postal']}'"; ?>/><br>
<label for="country">Land</label><select size="1" name="country">
<?php

$res = $db->query ('SELECT * FROM countries ORDER BY country');
while ($row = $res->fetch()) {
	echo '<option ';
	if (isset($_POST['country']))
		if ($_POST['country']==$row['id'])
			echo 'selected ';
	echo "value='{$row['id']}'>{$row['country']}</option><br/>\n";
}
?>
</select><br>
<input type="submit" value="opprett ny kontakt"/>
</body>
</html>