<!DOCTYPE html>
<html lang="no">
<head>
<title>Laboppgave 2</title>
</head>
<body>
<h1>Firkant</h1>
<?php
	for ($i=0; $i<10; $i++) {
		for ($j=0; $j<20; $j++)
			echo '*';
		echo '<br/>';
	}
?>

<h1>Trekant</h1>
<?php
	for ($i=0; $i<10; $i++) {
		for ($j=1; $j+$i*2>0; $j--)
			echo '*';
		echo '<br/>';
	}
?>

<h1>Pyramide</h1>
<?php
	for ($i=0; $i<10; $i++) {
		for ($j=$i*2; $j<18; $j++)
			echo '&nbsp;';
		for ($j=$i*2; $j+1>0; $j--)
			echo '*';
		echo '<br/>';
	}
?>

<h1>Pyramide 2</h1>
<?php
	for ($i=0; $i<10; $i++) {
		for ($j=0; $j<20; $j++)
			if (10-$i>$j) {
				echo '&nbsp;';
			} else {
				echo '*';
			}
		echo '<br/>';
	}
?>
</body>
</html>
