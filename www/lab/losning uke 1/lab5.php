<!DOCTYPE html>
<html>
<head>
<title>Stillingskategorier ved HiG</title>
</head>
<body>
<h1>Stillingskategorier ved HiG</h1>
<?php
$xml = simplexml_load_file('hig.xml'); 
$data = array ();
foreach ($xml->children() as $user) {
	foreach ($user->children() as $element=>$value)
		$data[$element] = "$value";
	if ($data['employee']=='y') {
		if (isset ($list[$data['department']][$data['title']])) // Vi har funnet en i denne kategorien før
			$list[$data['department']][$data['title']] += 1;
		else
			$list[$data['department']][$data['title']] = 1;	// Dette er den første i denne kategorien
	}
}
foreach ($list as $department=>$categories) {
	echo "<h2>$department</h2>\n<ul>\n";
	arsort ($categories);	// Sorterer på antall i hver kategori, behandler arrayen som en assosiativ array
	foreach ($categories as $category=>$number) {
		echo "<li>$category ($number)</li>\n";
	}
	echo "</ul>\n";
}
?>
</body>
</html>