<?php

/*
 * @author     Lars Kristian Dahl <http://www.krisd.com>
 * @copyright  Copyright (c) 2011 Lars Kristian Dahl <http://www.krisd.com>
 * @license    http://www.apache.org/licenses/LICENSE-2.0
 * @version    SVN: $Id$
 */

/**
 * Description of Database
 *
 * @author Lars Kristian Dahl <http://www.krisd.com>
 */
class Database {

    private $_dsn;
    static private $_dbh;

    private $_dbinfo = array (
            'type' => 'mysql',
            'host' => '127.0.0.1',
            'port' => 3306,
            'dbname' => 'jslab',
            'user' => 'root',
            'password' => '',
        );

    public function __construct(array $dbinfo=null) {
        ($dbinfo) ? $this->_dbinfo = $dbinfo : $dbinfo = $this->_dbinfo;
        $type = $dbinfo['type'];
        $host = $dbinfo['host'];
        $port = $dbinfo['port'];
        $dbname = $dbinfo['dbname'];
        $this->_dsn = "$type:host=$host;port=$port;dbname=$dbname;";
    }

    public function prepare($sql) {
        $this->connect();
        return self::$_dbh->prepare($sql);
    }

    public function exec($sql) {
        $this->connect();
        return self::$_dbh->exec($sql);
    }

    public function query($sql) {
        $this->connect();
        return self::$_dbh->query($sql);
    }

    public function beginTransaction() {
        $this->connect();
        self::$_dbh->beginTransaction();
    }

    public function commit() {
        $this->connect();
        self::$_dbh->commit();
    }

    public function rollback() {
        self::$_dbh->rollback();
    }

    /**
     * Performs lazy connection, only connecting to the DB when a query is actually performed
     * Also ensures that only 1 connection can be active, by returning the existing PDO object if one exists
     * @return <type>
     */
    public function connect() {
        if (!self::$_dbh instanceof \PDO) {
            try {
                self::$_dbh = new \PDO($this->_dsn, $this->_dbinfo['user'], $this->_dbinfo['password']);
                self::$_dbh->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
            } catch (\PDOException $e) {
                trigger_error($e->getMessage());
            }
        }
        return self::$_dbh;
    }

}