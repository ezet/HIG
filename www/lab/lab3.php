<!DOCTYPE html>
<html lang="no">
<head>
<link rel="stylesheet" type="text/css" href="/www/general.css"/>
</head>
<body>
<h1>Konvertere mellom cm og tommer</h1>

<?php
$format = '%04.2f';
if  (isset($_GET['cm']) && !empty($_GET['cm']))
	echo "<p>{$_GET['cm']} cm equals ". sprintf($format, $_GET['cm']/2.54). " inches</p>";
if  (isset ($_GET['inch']) && !empty($_GET['inch']))
	echo "<p>{$_GET['inch']} inches equals ". sprintf($format, 2.54*$_GET['inch']) ." cm</p>";
?>

Oppgi lengden i enter cm eller tommer og den konverteres til den andre enheten.
<form method="GET" action="<?php $_SERVER['PHP_SELF'] ?>">
<label for="cm">cm</label><input type="number" min="0" max="100" name="cm"/><br/>
<label for="inch">Tommer</label><input type="number" min="0" max="100" name="inch"/><br/>
<input type="submit" value="Konverter"/>
</form>



</body>
</html>