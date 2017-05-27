<?php

/*
 * @author     Lars Kristian Dahl <http://www.krisd.com>
 * @copyright  Copyright (c) 2011 Lars Kristian Dahl <http://www.krisd.com>
 * @license    http://www.apache.org/licenses/LICENSE-2.0
 * @version    SVN: $Id$
 */
include 'database.class.php';
$dbh = new Database;

try {
    $sql = 'DROP TABLE IF EXISTS YrLocation';
    $dbh->exec($sql);

    $sql = 'CREATE TABLE IF NOT EXISTS YrLocation (
    YrLocId int NOT NULL auto_increment,
    KommuneNr char(6) NOT NULL,
    Stedsnavn varchar(127) NOT NULL,
    Stedstype varchar(127) NOT NULL,
    Kommune varchar(127) NOT NULL,
    Fylke varchar(127) NOT NULL,
    Lat float NOT NULL,
    Lng float NOT NULL,
    Url varchar(127) NOT NULL,
    PRIMARY KEY (YrLocId)
    ); default charset=utf8';
    $dbh->exec($sql);

    $sql = 'INSERT INTO YrLocation (KommuneNr, Stedsnavn, Stedstype, Kommune, Fylke, Lat, Lng, Url) VALUES
 (:kommunenr, :stedsnavn, :stedstype, :kommune, :fylke, :lat, :lng, :url)';
    $sth = $dbh->prepare($sql);
    $lines = file('noreg.txt');
    foreach ($lines as $line) {
        $data = preg_split("/[\t]+/", $line);
        if ($data[0] * 1 != $data[0])
            continue;
        $sth->bindParam(':kommunenr', $data[0]);
        $sth->bindParam(':stedsnavn', $data[1]);
        $sth->bindParam(':stedstype', $data[4]);
        $sth->bindParam(':kommune', $data[6]);
        $sth->bindParam(':fylke', $data[7]);
        $sth->bindParam(':lat', $data[8]);
        $sth->bindParam(':lng', $data[9]);
        $sth->bindParam(':url', $data[11]);
        $sth->execute();
    }
} catch (PDOException $e) {
    trigger_error($e->getMessage(), E_USER_ERROR);
    die();
}