<?php
require_once 'db.php';

$data = file ('http://epab.posten.no/Norsk/Nedlasting/_Files/tilbud5.txt');
$sql = 'INSERT INTO postnr (postnr, poststed) VALUES (?, ?)';
$sth = $db->prepare ($sql);
foreach ($data as $postnr) {
	$postinfo = preg_split("[\t]", $postnr);
	$sth->execute (array ($postinfo[0], utf8_encode($postinfo[1])));
}
?>
Alle postnummer er lagt til i databasen.