<?php

/* 
 * @author     Lars Kristian Dahl <http://www.krisd.com>
 * @copyright  Copyright (c) 2011 Lars Kristian Dahl <http://www.krisd.com>
 * @license    http://www.apache.org/licenses/LICENSE-2.0
 * @version    SVN: $Id$
 */

require 'database.class.php';
$dbh = new Database;
//$sql = 'SELECT `Fylke`, AVG(`Lat`) AS Lat, AVG(`Long`) AS Long
//    FROM `YrLocation`
//    GROUP BY `Fylke`
//    ORDER BY `Fylke`';
$sql = 'SELECT Fylke as title, AVG(Lat) AS lat, AVG(Lng) AS lng
        FROM YrLocation
        GROUP BY Fylke
        ORDER BY Fylke';

try {
$sth = $dbh->prepare($sql);
$sth->execute();
$res = $sth->fetchAll(PDO::FETCH_ASSOC);
} catch (PDOException $e) {
    trigger_error($e->getMessage(), E_USER_ERROR);
}
echo json_encode($res);
