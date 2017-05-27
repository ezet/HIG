<?php
$dbinfo['dbuser'] = 'root';
$dbinfo['dbpassword'] = '';
$dbinfo['dbhost'] = '127.0.0.1';
$dbinfo['dbname'] = 'contacts';
$dbinfo['dbtype'] = 'mysql';
try {
	$dbh = new PDO("{$dbinfo['dbtype']}:host={$dbinfo['dbhost']}; dbname={$dbinfo['dbname']}", $dbinfo['dbuser'], $dbinfo['dbpassword']);
} catch (PDOException $e) {
	die ('Could not connect to database : ' . $e->getMessage());
}
?>