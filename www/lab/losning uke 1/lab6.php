<?php
$xml = simplexml_load_file('http://www.dnbnor.no/portalfront/datafiles/miscellaneous/csv/kursliste_ws.xml');
foreach ($xml->children() as $valutakurs) {
  if (count($valutakurs->children())<2)
	  continue;
	$valutakurser[$valutakurs->land.', '.$valutakurs->navn]['enhet'] = $valutakurs->enhet+0;
	$valutakurser[$valutakurs->land.', '.$valutakurs->navn]['salg'] = floatval($valutakurs->seddel->salg);
}
ksort ($valutakurser);
?>
<!DOCTYPE html>
<html>
<head>
<title>Valutakalkulator</title>
</head>
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
<body>
<h1>Valutakalkulator</h1>
<?php
if (isset ($_POST['amount'])) {
	$rate = $valutakurser[$_POST['valuta']]['salg'];
	$enhet = $valutakurser[$_POST['valuta']]['enhet'];
	list ($land, $valuta) = preg_split ('[ ]', $_POST['valuta']);
	if ($_POST['amount']%$enhet!=0) {
		echo "<h3>Du må oppgi ønsket beløp i hele {$valutakurser[$_POST['valuta']]['enhet']} ";
		echo "$valuta</h3>";
	} else {
		echo "<h3>For {$_POST['amount']} $valuta må du betale ";
		echo $_POST['amount']*$valutakurser[$_POST['valuta']]['salg']/$valutakurser[$_POST['valuta']]['enhet'];
		echo " norske kroner</h3>";
	}
}?>
<form method="post" action="lab6.php">
<label for="valuta">Velg valuta</label><select name="valuta" size="1">
<?php
foreach ($valutakurser as $valuta=>$kurs)
	if ($valuta==$_POST['valuta'])
		echo "<option selected value='$valuta'>$valuta</option>\n";
	else
		echo "<option value='$valuta'>$valuta</option>\n";
?></select><br>
<label for="amount">Hvor mye ønsker du å kjøpe</label><input name="amount" type="number" min="1" <?php
if (isset ($_POST['amount']))
	echo "value='{$_POST['amount']}' ";
?>/><br/>&nbsp;<br/>
<input type="submit" value="Beregn kostnad"/>
</form>
</body>
</html>5