<!DOCTYPE html>
<html>
<head>
<title>Valutakalkulator</title>
</head>
<body>
<h1>Valutakalkulator</h1>
<?php
$xml = simplexml_load_file('kursliste_ws.xml');
foreach ($xml->children() as $valutakurs) {
  if (count($valutakurs->children())<2)
	  continue;
	$valutakurser[$valutakurs->land.', '.$valutakurs->navn]['enhet'] = $valutakurs->enhet+0;
	$valutakurser[$valutakurs->land.', '.$valutakurs->navn]['salg'] = floatval($valutakurs->seddel->salg);
}
echo '<pre>';
print_r ($valutakurser);
echo '</pre>';
?>
</body>
</html>
	