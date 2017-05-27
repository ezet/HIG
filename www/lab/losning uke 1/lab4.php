<!DOCTYPE html>
<html>
<head>
<title>Professorer ved HiG</title>
</head>
<body>
<h1>Professorer ved HiG</h1>
<?php
$xml = simplexml_load_file('hig.xml'); 
$data = array ();
foreach ($xml->children() as $user) {
	foreach ($user->children() as $element=>$value)
		$data[$element] = "$value";
	if (stripos ($data['title'], 'Professor')===false) {
	} else {
		$list[$data['department']][] = $data['givenname'].' '.$data['surename'];
	}
}
foreach ($list as $department=>$professors) {
	echo "<h2>$department</h2>\n<ul>\n";
	foreach ($professors as $professor) {
		echo "<li>$professor</li>\n";
	}
	echo "</ul>\n";
}
?>
</body>
</html>