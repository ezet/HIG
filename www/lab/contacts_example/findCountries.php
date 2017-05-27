<?php
$countries = array ();
$data = file ('http://www.listofcountriesoftheworld.com/');
foreach ($data as $country) {
	if (strpos ($country, '</td><td><a href=')>0) {
		$idx = strpos ($country, '</td><td><a href=');
		$idx += 27;
		$idx1 = strpos ($country, '</a>', $idx);
		$countries[] = substr ($country, $idx, $idx1-$idx);
	}
}

// print_r ($countries);	// Quick check for debugging purposes, when this is correct it works :)
require_once 'db.php';
$sql = 'INSERT INTO countries (country) VALUES (?)';
$sth = $db->prepare ($sql);
foreach ($countries as $country) 
	$sth->execute (array ($country));
?>
Alle land er lagt til i databasen.