<!DOCTYPE html>
<html lang="no">
<head>
<link rel="stylesheet" type="text/css" href="general.css"/>
</head>
<body>
<?php
$xml = simplexml_load_file('hig.xml');
$data = array();
foreach ($xml->children() as $users) {
	foreach ($users->children() as $key=>$value)
		$data[$key] = "$value";
	if ($data['employee'] == 'y') {
		if (isset($list[$data['department']][$data['title']]))
			$list[$data['department']][$data['title']] += 1;
		else
			$list[$data['department']][$data['title']] = 1;
	}
}

foreach ($list as $department=>$titles) {
	echo "<h2>$department</h2>\n<ul>\n";
	arsort($titles);
	foreach ($titles as $title=>$count)
		echo "<li>$title ($count)</li>\n";
	echo '</ul>';
}