<?php
require_once('config.inc.php');

$error = array();
$errormsg = 'Cannot perform operation<br/>';
isValidUid($error);


if (isset($_POST['submit']) && $_POST['submit'] == 'addinfo') {
	if (!isset($_POST['contactinfo']) || empty($_POST['contactinfo']))
		$error[] = 'Missing input field: Contact information';
	if (!isset($_POST['type']) || empty($_POST['type']))
		$error[] = 'Missing input field: Type';
	if (!$error) {
		$sql = 'INSERT INTO contactinfo (uid, type, contactinfo, description) values (?, ?, ?, ?)';
		$sth = $dbh->prepare($sql);
		$sth->execute(array ($_GET['uid'], $_POST['type'], $_POST['contactinfo'], $_POST['description']));
	}
} ?>


<!DOCTYPE html>
<html>
<head>
<title>Add contact information</title>
<script type="text/javascript">
function done() {
	if (window.opener.location.href.indexOf("?")>-1)
		window.opener.location.href = window.opener.location.href;
	else
		window.opener.location.href = window.opener.location.href+"?uid=<?php echo $_GET['uid']; ?>";
	window.close();
}
</script>
<link rel="stylesheet" type="text/css" href="/www/style.css"/>
</head>
<body
<?php if (isset($_POST['action']) && ($_POST['action'] == 'submit') && !$error)
	echo "onload='done();'";
echo '>';
if ($error) {
	echo $errormsg;
	foreach ($error as $err)
		echo $err, '<br/>';
} ?>
<h4>Add new information</h4>
<form method="POST">
<label for="type">Type</label><select name="type">
<?php
$sql = 'SHOW COLUMNS FROM contactinfo LIKE "type"';
$result = $dbh->query($sql)->fetch();
preg_match_all("/'(.*?)'/", $result['Type'], $enums);
foreach ($enums[1] as $value) {
	echo '<option value="', $value, '"';
	if (isset($_POST['type']) && $value == $_POST['type']) echo ' selected ';
	echo '">', $value, '</option>';
}
?>
</select><br/>
<label for="contactinfo">Contact information</label>
<input name="contactinfo" type="text" value="<?php if (isset($_POST['contactinfo'])) echo $_POST['contactinfo']; ?>" placeholder="contact information"/><br/>
<label for="description">Descripion</label><input name="description" type="text" value="<?php if (isset($_POST['description'])) echo $_POST['description']; ?>" placeholder="description"/><br/>
<input name="submit" value="addinfo" type="hidden"/>
<input type="submit" value="Submit"/>
</form>
	
<?php
require_once('footer.php');
?>