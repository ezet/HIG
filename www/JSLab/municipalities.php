<?php

/* 
 * @author     Lars Kristian Dahl <http://www.krisd.com>
 * @copyright  Copyright (c) 2011 Lars Kristian Dahl <http://www.krisd.com>
 * @license    http://www.apache.org/licenses/LICENSE-2.0
 * @version    SVN: $Id$
 */

require 'database.class.php';
$dbh = new Database;

$sql = 'SELECT Kommune as title, AVG( Lat ) AS lat, AVG( Lng ) AS lng
        FROM YrLocation
        WHERE Fylke = :Fylke
        GROUP BY Kommune
        ORDER BY Kommune';

try {
$sth = $dbh->prepare ($sql);
$sth->bindParam (':Fylke', $_GET['county']);
$sth->execute();
$res = $sth->fetchAll(PDO::FETCH_ASSOC);
} catch (PDOException $e) {
    trigger_error($e->getMessage(), E_USER_ERROR);
}
echo json_encode($res);