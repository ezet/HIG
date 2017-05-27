<?php
require_once('functions.inc.php');
require_once('contact.class.php');

$db['type'] = 'mysql';
$db['host'] = '127.0.0.1';
$db['name'] = 'contacts';
$db['user'] = 'root';
$db['password'] = '';

try {
	$dbh = new PDO("{$db['type']}:host={$db['host']}; dbname={$db['name']}", $db['user'], $db['password']);
} catch (PDOExceptin $e) {
	die ('Could not connect to database : ' . $e->getMessage());
}