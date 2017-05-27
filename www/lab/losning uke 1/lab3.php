<!DOCTYPE html>
<html>
<head>
<title>Enhetskalkulator</title>
<style type="text/css">
label {
	width: 120px;
	float: left;
	text-align: right;
	padding-right: 5px;
}

input {
  width: 200px;
}

input[type="number"] {
  width: 50px;
}

input[type="date"] {
  width: 100px;
}
</style>
</head>
<body>
<h1>Konvertere mellom cm og tommer</h1>
<?php
// To desimaler : sprintf("%01.2f", $tallet)

if (isset($_POST['inch'])&&($_POST['inch']!=''))
	echo "<p>{$_POST['inch']} tommer tilsvarer ".(2.54*$_POST['inch'])." cm</p>";
if (isset($_POST['cm'])&&($_POST['cm']!=''))
	echo "<p>{$_POST['cm']} cm tilsvarer  ". ($_POST['cm']/2.54)." tommer</p>";
?>
Oppgi lengden i enten cm eller tommer og den konverteres til den andre enheten.
<form method="post" action="lab3.php">
<label for="c">cm</label><input type="number" min="0" max="1000" name="cm"/><br/>
<label for="f">Tommer</label><input type="number" min="0" max="500" name="inch"/><br/>
<input type="submit" value="Konverter"/>
<form>
</body>
</html>