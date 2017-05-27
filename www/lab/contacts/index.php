<?php
require_once('header.php');

// DISPLAY LIST OF CONTACTS
$sql = 'SELECT id, firstname, lastname FROM people ORDER BY lastname';
PrintContacts($sql, REVERSE);


require_once('footer.php');
?>




