<?php
require_once 'db.php';
if (isset ($_POST['contactinfo'])) {
	$sql = 'INSERT INTO contactinfo (uid, type, contactinfo, description) VALUES (:uid, :type, :contactinfo, :description)';
	$sth = $db->prepare ($sql);
	$sth->bindParam (':uid', $_POST['uid']);
	$sth->bindParam (':type', $_POST['type']);
	$sth->bindParam (':contactinfo', $_POST['contactinfo']);
	$sth->bindParam (':description', $_POST['description']);
	$sth->execute ();
} else {
	$sql = 'SELECT CONCAT(givenname, " ", surename) as name from people where id=:id';
	$sth = $db->prepare ($sql);
	$sth->bindParam (":id", $_GET['id']);
	$sth->execute();
	$row = $sth->fetch();
	$name = $row['name'];
}
?><!DOCTYPE html>
<html>
<head>
<title>Legg til kontaktinformasjon</title>
<script type="text/javascript">
function done() {
	if (window.opener.location.href.indexOf("?")>-1)
		window.opener.location.href = window.opener.location.href;
	else
		window.opener.location.href = window.opener.location.href+"?id=<?php echo $_POST['uid']; ?>";
	window.close();
}
</script>
<link rel="stylesheet" type="text/css" href="styles.css"/>
</head>
<body <?php 
if (isset ($_POST['action']))
	echo "onload='done();'";
?>>
<h1>Legg til kontaktinformasjon for <?php echo $name; ?></h1>
<form method="post" action="addcontactinfo.php">
<input type="hidden" name="uid" value="<?php echo $_GET['id']; ?>"/>
<label for="type">Type</label><select name="type" size="1">
<option value="phone">Telefon</option>
<option value="email">E-Post</option>
<option value="web">Web</option>
<option value="chat">Chat (msn, ICQ, etc)</option>
<option value="fax">Fax</option></select> <br/>
<label for="contactinfo">Kontaktinfo</label><input type="text" name="contactinfo"/><br/>
<label for="description">Beskrivelse</label><input type="text" name="description"/><br/>
<input type="submit" value="Legg til kontaktinformasjon"/>
</body>
</html>