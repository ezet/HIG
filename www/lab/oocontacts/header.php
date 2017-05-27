<?php
require_once('config.inc.php');
?>
<!DOCTYPE html>
<html>
<head>
<title>Contacts</title>
<link rel="stylesheet" type="text/css" href="/www/style.css"/>
<script type="text/javascript">
function addContactinfo(id) {
	window.open ("addinfo.php?uid="+id, "newcontactinfo", "width=500,height=400");
}
</script>
</head>
<body>
<h1>Contacts</h1>
This is a basic application for handling contacts.<br/><br/>
<?php
require_once('menu.inc.php'); ?>

<?php //require_once('search.inc.php'); ?>
<form method="POST" action="search.php">
<input name="search" type="text" placeholder="Search..."/>
</form>

<hr/>
