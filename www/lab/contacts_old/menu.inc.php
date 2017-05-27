<a href="index.php">Home<a> 
<a href="index.php?page=contacts&action=new">New contact</a>

<?php 
if (!isset($_GET['action']) || $_GET['action'] != 'delete')
	if (isset($_GET['uid']) && !empty($_GET['uid'])) {
		echo '<a href="index.php?page=details&action=edit&uid='.$_GET['uid'].'">Edit contact</a> ';
		echo '<a href="index.php?page=details&action=addinfo&uid='.$_GET['uid'].'">Add contactinfo</a> ';
		echo '<a href="index.php?page=contacts&action=delete&uid='.$_GET['uid'].'">Delete contact</a> ';
} ?>
<a href="index.php?page=admin&action=resetdb"/>Reset DB</a>
