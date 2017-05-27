<?php
require('header.php');

if ($_GET['action'] == 'dbreset') {

	// REPLACE TABLES
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

		
	// INSERTING DATA

	// Inserting postal information
	$dbh->exec('DELETE FROM postalcodes');
	$sql = 'INSERT INTO postalcodes (postalcode, postal) values (:postalcode, :postal)';
	$sth = $dbh->prepare($sql);
	$data = file ('http://epab.posten.no/Norsk/Nedlasting/_Files/tilbud5.txt');
	foreach ($data as $postinfo) {
		$postinfo = preg_split("[\t]", $postinfo);
		$sth->bindParam(':postalcode', $postinfo[0]);
		$sth->bindParam(':postal', $postinfo[1]);
		$sth->execute();
	}


	// Inserting list of countries
	$dbh->exec('DELETE FROM countries');
	$sql = 'INSERT into countries (country) values (:country)';
	$sth = $dbh->prepare($sql);
	$data = file ('http://www.listofcountriesoftheworld.com/');
	foreach ($data as $value)
		if (strlen($value) > 25)
			if ($start = strpos($value, '.html">', 25)) {
				$country = substr($value, $start+7, (strpos($value, '</a>') - ($start+7)));
				$sth->bindParam(':country', $country);
				$sth->execute();
			}


	// Inserting people
	$dbh->exec('DELETE FROM people');
	$sql = 'INSERT into people (firstname, lastname, address, postalcode, postal, country) values (?, ?, ?, ?, ?, ?)';
	$sth = $dbh->prepare($sql);
	$data = file('people.txt');
	foreach ($data as $person) {
		$person = preg_split("[\t]", $person);
		var_dump($person);
		$sth->execute(array ($person[0], $person[1], $person[2], $person[3], $person[4], trim($person[5])));
	}
}
require('footer.php');
?>