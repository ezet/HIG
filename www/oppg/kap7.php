<?php session_start(); ?>
<!DOCTYPE html>
<html>
<head>
<title>Oppgaver, kapittel 7</title>
<link rel="stylesheet" type="text/css" href="/www/general.css"/>
</head>
<body>
<h3>Oppgave 7.1</h3>
<?php
if (isset($_GET['name']) && !empty($_GET['name'])) {
	foreach ($_GET as $key => $value)
		setcookie("profile[$key]", $value);
}
?>
<form method="GET">
<label for="name">Your name</label><input name="name" type="text"/><br/>
<label for="fontname">Font type</label><input name="fontname" type="text"/><br/>
<label for="fontsize">Font size</label><input name="fontsize" type="number" min="8" max="14"/><br/>
<label for="fontcolor">Font color</label><input name="fontcolor" type="text"/><br/>
<input type="submit" value="Save"/>
</form>

<h3>Oppgave 7.2</h3>
<?php
if (isset($_SESSION))
	var_dump($_SESSION);

if (isset($_GET['item'])) {
	echo 'item is set';
	var_dump($_GET);
	foreach ($_GET['item'] as $item => $amount) {
		if (isset($_SESSION[$item]))
			$_SESSION[$item] += $amount;
		else
			$_SESSION[$item] = $amount;
	}
}

$items = array();

for ($i = 1; $i <= 10; $i++) {
	$items["item$i"] = $i+10;
	echo '<form method="GET">';
	echo 'Item' . $i . ' ' . ($i+10) . ',- <input name="item[item'.$i.']" type="number" value="1" min="1"/><input type="submit" value="Buy"/><br/><br/>';
	echo '</form>';
}
//var_dump($items);

?>


</body>
</html>