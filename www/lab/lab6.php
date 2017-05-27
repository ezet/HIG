<!DOCTYPE html>
<?php
$xml = simplexml_load_file('kursliste_ws.xml');
foreach ($xml->children() as $valutakurs) {
  if (count($valutakurs->children())<2)
	  continue;
	$valutakurser[$valutakurs->land.', '.$valutakurs->navn]['enhet'] = $valutakurs->enhet+0;
	$valutakurser[$valutakurs->land.', '.$valutakurs->navn]['salg'] = floatval($valutakurs->seddel->salg);
}
ksort($valutakurser);
?>

<html>
<head>
<title>Valutakalkulator</title>
<link rel="stylesheet" type="text/css" href="general.css"/>
</head>
<body>
<h1>Valutakalkulator</h1>
<?php
if (isset ($_POST['amount'])) {
	$rate = $valutakurser[$_POST['valuta']]['salg'];
	$enhet = $valutakurser[$_POST['valuta']]['enhet'];
	$list ($land, $valuta) = preg_split('[ ]', $_POST['valuta'];
	if ($_POST
}
?>

<form method="post" action="lab6.php">
<label for="valuta">Velg valuta</label>
<select name="valuta">
<?php
foreach ($valutakurser as $valuta=>$kurs)
	if ($valuta==$_POST['valuta'])
		echo "<option selected value='$valuta'>$valuta</option>\n";
	else
		echo "<option value='$valuta'>$valuta</option>\n";
?>
</select><br/>
<label for="amount">Hvor mye</label>
<input type="number" min="1" name="amount" value="<?php if (isset ($_POST['amount'])) echo $_POST['amount'] ?>"/><br/>
<input type="submit" value="Beregn kostnad"/>
</form>
</body>
</html>