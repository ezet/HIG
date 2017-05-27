<?php

/* 
 * @author     Lars Kristian Dahl <http://www.krisd.com>
 * @copyright  Copyright (c) 2011 Lars Kristian Dahl <http://www.krisd.com>
 * @license    http://www.apache.org/licenses/LICENSE-2.0
 * @version    SVN: $Id$
 */

header ("Content-Type: application/xhtml+xml; charset=UTF-8");
$url = $_GET['url'];
$url = str_replace ('Ø', '%d8', $url);
$url = str_replace ('ø', '%f8', $url);
$url = str_replace ('Æ', '%c6', $url);
$url = str_replace ('æ', '%e6', $url);
$url = str_replace ('Å', '%c5', $url);
$url = str_replace ('å', '%e5', $url);
readfile($url);
