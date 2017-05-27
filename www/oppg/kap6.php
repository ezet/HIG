<!DOCTYPE html>
<html>
<head><title>Oppgaver, kapittel 6</title>
<link rel="stylesheet" type="text/css" href="general.css"/>
</head>
<body>
<h1>Oppgaver, kapittel 6</h1>
<p
<?php echo (date('D') == 'Sat') ?  'style="color: green"' : ''; ?>
>Good 
<?php echo (date('a') == 'am') ? 'morning' : 'evening'; ?>.</p>

<?php
$img = date('s') % 10;
//echo '<img src="' . $img . '.png">';
echo $img;
?>
<br/><br/>
<?php
function cCrypt($string, $key="5", $mode="0") {
	//$string = lcwords($string);
	$i = 0;
	if ($mode) $key = 26 - $key;
	while ($i < strlen($string)) {
		$offset = (ord($string[$i]) > 90) ? 97 : 65;
		$string[$i] = chr(((ord($string[$i])+$key) - $offset) % 26 + $offset);
		$i++;
	}
	return $string;
}

echo '<h3>Oppgave 6.4</h3>';

$string = 'xyz';
echo $crypt = cCrypt($string, 1);
echo cCrypt($crypt, 1, 1);
echo '<br/><br/>';

function mCrypt($string, $key="5", $mode="0") {
	if ($mode)
		$key = ceil(strlen($string) / $key);
	$smat = str_split($string, $key);
	while (strlen(end($smat)) < $key && !$mode)
		$smat[key($smat)] .= ' ';	
	//var_dump($smat);
	$newString = '';
	for ($i = 0; $i < $key; $i++)
		foreach ($smat as $s)
			if ($i < strlen($s))
				$newString .= $s[$i];
	return $newString;
}

function mDecrypt($string, $key="5") {
	$rkey = ceil(strlen($string) / $key);
	$smat = str_split($string, $rkey);
	//var_dump($smat);
	$newString = '';
	for ($i = 0; $i < $rkey; $i++) {
		foreach ($smat as $s) {
			if ($i < strlen($s))
				$newString .= $s[$i];
		}
	}
	return $newString;
}

$string = 'Hovedstaden i Norge er Oslo!';
$key = 5;
echo $string = mCrypt($string, $key);
echo $string = mCrypt($string, $key, 1);

function doCrypt($string, $algo, $mode="0", $key="5") {
	return ($algo) ? mCrypt($string, $key, $mode) : cCrypt($string, $key, $mode);
	//if ($algo) return mEncrypt($string, $key);
	//else return cCrypt($string, $key, $mode);
}
	
echo '<h3>Kryptografi</h3>';

if (isset($_GET['algo'])) {
	echo $string = doCrypt($_GET['string'], $_GET['algo'], $_GET['mode'], $_GET['key']);
}

?>
<form method="GET">
<label for="string">Type text</label><input type="text" name="string" value="<?php echo (isset($_GET['string']) ? $string : ''); ?>"/><br/>
<label for="algo">Chooose algorithm</label>
<select name="algo">
<option value="0" <?php if (isset($_GET['algo']) && $_GET['algo'] == 0) echo 'selected'; ?>>Caesars algorithm</option>
<option value="1" <?php if (isset($_GET['algo']) && $_GET['algo'] == 1) echo 'selected'; ?>>Matrix algorithm</option>
</select>
<select name="mode">
<option value="0">Encrypt</option>
<option value="1">Decrypt</option>
</select>
<br/>
<label for="key">Choose key</label><input type="number" name="key" min="1" max="10" value="<?php echo (isset($_GET['key']) ? $_GET['key'] : '5'); ?>"/><br/>
<input type="submit" value="Go"/>
</form>


</body>
</html>