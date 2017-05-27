<?php

// Show search results
if (isset($_GET['search'])) {
	$search = "%{$_GET['search']}%";
	$sql = 'SELECT id, firstname, lastname FROM people WHERE firstname LIKE "'.$search.'" OR lastname LIKE "'.$search.'" ORDER BY lastname';
	$sth = $dbh->query($sql);
	echo '<p>Found ' . $sth->rowCount() . ' matches:</p>';
	foreach ($sth as $row) {
		echo '<a href="?page=details&uid='.$row['id'].'">';
		echo $row['lastname'] . ', ' . $row['firstname'] . '</a><br/>';
		}
	}
?>