<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of contact
 *
 * @author ezet
 */
class Contact {

    function __construct() {
        $this->init();
    }

    function isValidUid() {
        return (!isset($this->$error['uid']));
    }

    private function init() {
        $this->checkUid();
        if (isValidUid())
            $this->fetchData();
    }

    private function checkUid() {
        global $dbh;
        if (!isset($_GET['uid']) || empty($_GET['uid'])) {
            $this->$error['uid'] = 'Missing parameter UID';
        } else {
            $this->uid = $_GET['uid'];
            $sql = 'SELECT * FROM people WHERE id = ?';
            $this->sth = $dbh->prepare($sql);
            $this->sth->execute(array($this->uid));
            if (!$this->sth->rowCount())
                $this->$error['uid'] = 'UID does not exist';
        }
    }

    private function fetchData() {
        $array = $this->sth->fetch(PDO::FETCH_ASSOC);
        foreach ($array as $key => $value)
            $this->$key = $value;
    }

    function getName($mode=0) {
        if ($mode)
            return $name = "$lastname, $fistname";
        else
            return $name = "$firstname $lastname";
    }

    function update() {
        global $dbh;
        $sql = 'UPDATE people SET firstname = ?, lastname = ?, address = ?, postalcode = ?, postal = ?, country = ? WHERE id = ?';
        $sth = $dbh->prepare($sql);
        $sth->execute(array($_GET['firstname'], $_GET['lastname'], $_GET['address'], $_GET['postalcode'], $_GET['postal'], $_GET['country'], $_GET['uid']));
        echo $_GET['firstname'] . ' ' . $_GET['lastname'] . ' has been successfully updated.';
    }

    public $error = array();
    
    private $sth;
    
    private $uid;
    private $firstname;
    private $lastname = null;
    private $address = null;
    private $postalcode = null;
    private $postal = null;
    private $country = null;
    private $countryname = null;

}

?>
