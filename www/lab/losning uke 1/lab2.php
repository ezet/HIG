<!DOCTYPE html>
<html>
<head>
<title>Fine mønstre</title>
</head>
<body>
<h1>Firkant</h1>
<pre>
<?php
for ($i=0; $i<10; $i++) {
  for ($ii=0; $ii<20; $ii++)
		echo '*';
	echo "\n";
}
?>
</pre>
<h1>Trekant</h1>
<pre>
<?php
for ($i=0; $i<10; $i++) {
  for ($ii=0; $ii<$i*2+1; $ii++)
		echo '*';
	echo "\n";
}
?>
</pre>
<h1>Pyramide</h1>
<pre>
<?php
for ($i=0; $i<10; $i++) {
  for ($ii=0; $ii<(20-$i*2)/2; $ii++)
		echo ' ';
	for ($ii=0; $ii<$i*2+1; $ii++)
		echo '*';
	echo "\n";
}
?>

</body>
</html>