<?php

// Oppgave 5.2
/*
function calcAreal($h, $w) {
	return $w * $h;
}

function calcAreal2($h, $w, $l=0) {
	if ($l == 0)
		return $w * $h;
	else
		return $w * $h * $l;
}

$cube = array ('width' => 6, 'height' => 4, 'length' => 3);

echo calcAreal2($cube['width'], $cube['height']);


for ($i = 1; $i < 31; $i++)
	echo '<br/>'.calcAreal2($i, $i);
*/

// Oppgave 5.3
$matrix = array(1, 5, 4, 3);
$matrix2 = array(1, 5, 4, 3);

function numElements(&$matrix) {
	$num = 0;
	foreach ($matrix as $value)
		$num++;
	return $num;
}

function getMax(&$matrix) {
	$max;
	foreach ($matrix as $value)
		if (!isset($max) || $value > $max)
			$max = $value;
	return $max;
}

function getMin(&$matrix) {
	$min;
	foreach ($matrix as $value)
		if (!isset($min) || $value < $min)
			$min = $value;
		return $min;
}

function isIdentical(&$m1, &$m2) {
	$equal = 0;
	foreach ($m1 as $key1 => $value1) {
		foreach ($m2 as $key2 => $value2) {
			if ($m1 == $m2 && $value1 == $value2)
				$equal = 1;
		}
		if (!$equal)
			return 0;
		$equal = 0;
	}
	return 1;
}

function parseMatrix($s, $mat) {
	$string = '';
	foreach ($mat as $value) {
		if ($string != '')
			$string .= $s;
		$string .= $value;
	}
	return $string;
}
		
echo '<br/>The matrix has ' . numElements($matrix) . ' elements.';
echo '<br/>Max value is ' . getMax($matrix);
echo '<br/>Min value is ' . getMin($matrix);
echo '<br/>Identical: ' . isIdentical($matrix, $matrix2);
echo '<br/>Parsed matrix: ' . parseMatrix('+++', $matrix);
?>
	