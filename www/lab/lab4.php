<!DOCTYPE html>
<html lang="no">
<head>
<link rel="stylesheet" type="text/css" href="/www/general.css"/>
</head>
<body>
<?php
$xml = simplexml_load_file('hig.xml');
$list;
function PrintStaff($data) {
echo '<li>'.$data['givenname'].' '.$data['surename'].'</li>';
}

// Retrieving departments
foreach ($xml->children() as $user) {
	foreach ($user->children() as $key=>$value)
		$data[$key] = "$value";
	if (stripos($data['title'], 'professor') !== false)
		$list[$data['department']][] = "{$data['givenname']} {$data['surename']}";
}

foreach ($list as $department=>$professors) {
	echo "<h1>$department</h1>\n<ul>\n";
	foreach ($professors as $professor)
		echo "<li>$professor</li>\n";
	echo '</ul>';
}

?>
</body>
</html>