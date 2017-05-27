<?php

// Oppgaver, kapittel 4

$arr1 = array ('apple' => 1, 'orange' => 2);
$arr2['apple'] = 1;
$arr2['orange'] = 2;

$sum = 0;

foreach ($arr1 as $price)
	$sum += $price;

echo 'Sum: ' . $sum . '<br/>Average: ' . $sum / count($arr1);

$max = 0;
$min = 5;
foreach ($arr1 as $price) {
	if ($price < $min)
		$min = $price;
	if ($price > $max)
		$max = $price;
}
echo $min . ' ' . $max;


?>
<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="general.css"/>
</head>
<body>
<?php
if (isset ($_GET['name'])) {
	echo $_GET['name'] . ', your interests are:<br/>';
	foreach ($_GET['interests'] as $interest)
		echo $interest . '<br/>';
}
?>

<form method="GET">
<label for="name">Your name</label><input type="text" name="name"/><br/>
<label for="interests">Pick your interests</label><select name="interests[]" multiple>
<option value="sports">Sports</option>
<option value="food">Food</option>
<option value="programming">Programming</option>
</select>
<input type="submit" value="Hit it"/>
</form>
</body>
</html>