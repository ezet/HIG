<?php ?>
<ul class="mainmenu">
<li><a href="index.php">Home</a></li>
<li><a href="add.php">Add contact</a></li>
<?php
if (isset($_GET['uid']) && !empty($_GET['uid'])) {
	$uid = $_GET['uid'];
	echo '<li><a href="edit.php?uid='.$uid.'">Edit contact</a></li>';
	echo '<li><a href="javascript:addContactinfo(', $uid, ');">Add contactinfo</a></li>';
	echo '<li><a href="details.php?action=delete&uid='.$uid.'">Delete contact</a></li>';
}
?>
<li><a href="admin.php?action=dbreset">Reset DB</a></li>
</ul>