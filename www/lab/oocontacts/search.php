<?php
require_once('config.inc.php');

if (isset($_POST['search'])) {
	$search = "%$search%";
	$sql = 'SELECT id, firstname, lastname FROM people WHERE firstname LIKE "'.$search.'" OR lastname LIKE "'.$search.'" ORDER BY lastname';
	$count = $dbh->query($sql)->rowCount();
}

// BEGIN HTML	
require_once('header.php');
	if ($count) {
		echo "Found $count match";
		echo ($count==1) ? ':' : 'es:';
		PrintContacts($sql, REVERSE);
	} else
		echo 'No matches found.';
require_once('footer.php'); ?>