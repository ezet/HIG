<?php
require_once('dbconnect.inc.php')
?>
<!DOCTYPE html>
<html>
<head>
<title>Addressbook</title>
<link rel="stylesheet" type="test/css" href="/www/general.css"/>
</head>
<body>
<h2>Contacts</h2>
This is a basic application for handling contacts.<br/><br/>
<?php
include('menu.inc.php');

// SEARCH ?>
<form method="GET">
<input type="hidden" name="page" value="search"/>
<input type="hidden" name="action" value="search"/>
<input type="text" name="search" placeholder="Search..."/>
</form>
<?php
echo '<hr>';

if (isset($_GET['page']))
	include($_GET['page'] . '.inc.php');
else
	include('contacts.inc.php');


?>
</body>
</html>