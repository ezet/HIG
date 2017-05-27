<?php
require_once('dbconnect.inc.php');

$sql[] = 'DROP TABLE people, countries, postalcodes, contactinfo';

$sql[] = 'CREATE TABLE people (
id INT NOT NULL AUTO_INCREMENT,
firstname VARCHAR(128) NOT NULL,
lastname VARCHAR(128),
address VARCHAR(128),
postalcode CHAR(4) NOT NULL,
postal VARCHAR(128),
country INT(11) NOT NULL,
PRIMARY KEY (`id`)
);';

$sql[] = 'CREATE TABLE countries (
id INT NOT NULL AUTO_INCREMENT,
country VARCHAR(128) NOT NULL,
PRIMARY KEY (`id`)
);';

$sql[] = 'CREATE TABLE postalcodes (
postalcode CHAR(4) NOT NULL,
postal VARCHAR(128),
PRIMARY KEY (`postalcode`)
);';

$sql[] = 'CREATE TABLE contactinfo (
id INT NOT NULL AUTO_INCREMENT,
uid INT(11) NOT NULL,
type ENUM("email", "phone", "fax", "chat", "web") NOT NULL,
contactinfo VARCHAR(128) NOT NULL,
description VARCHAR(128),
PRIMARY KEY (`id`)
);';

foreach ($sql as $query)
	$dbh->exec($query);
?>
