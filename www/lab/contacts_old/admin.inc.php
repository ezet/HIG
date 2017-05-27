<?php

if ($_GET['action'] == 'resetdb') {
	include('dbcreate.inc.php');
	include('dbfill.inc.php');
}
?>