<?php
require_once 'db.php';
?><!DOCTYPE html>
<html>
<head>
<title>Søker etter "<?php echo $_POST['search']; ?>"</title>
</head>
<body>
<a href="index.html">Tilbake til adresseboken</a>
<h1>Søker etter "<?php echo $_POST['search']; ?>"</h1>
<?php
$sql = 'SELECT * FROM people WHERE CONCAT(givenname, " ", surename) LIKE :search ORDER BY surename, givenname';
$sth = $db->prepare ($sql);
$search = '%'.$_POST['search'].'%';
$sth->bindParam (':search', $search);
$sth->execute ();
while ($row = $sth->fetch()) {
	echo "<a href='details.php?id={$row['id']}'>{$row['givenname']} {$row['surename']}</a><br/>\n";
}
?>
</body>
</html>