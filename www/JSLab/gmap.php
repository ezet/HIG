<?php
/*
 * @author     Lars Kristian Dahl <http://www.krisd.com>
 * @copyright  Copyright (c) 2011 Lars Kristian Dahl <http://www.krisd.com>
 * @license    http://www.apache.org/licenses/LICENSE-2.0
 * @version    SVN: $Id$
 */

define('__BASE_URL', 'http://localhost:8888/JSLab');
?>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <meta http-equiv="Content-Script-Type" content="text/javascript">
        <meta name="viewport" content="initial-scale=1.0, user-scalable=no" />
        <style type="text/css">
            html { height: 100%; }
            body { height: 100%; margin: 0px; padding: 0px; }
            form { float: left; }
            #map-canvas { height: 500px; width: 500px; }
            #map-wrapper { float: right; padding: 10px; }
        </style>

        <script type="text/javascript" src="https://www.google.com/jsapi?key=T4CYxutQFHLDudcGlaN5m7lyeCsBKLxQ"></script>

        <script type="text/javascript" src="http://maps.google.com/maps/api/js?sensor=false"> </script>
        <script type="text/javascript">
            google.load("jquery", "1.5.1", { uncompressed: true });
            _base_url = '<?php echo __BASE_URL; ?>';
        </script>

        <script type="text/javascript" src="<?php echo __BASE_URL; ?>/init.js"> </script>
        <script type="text/javascript" src="<?php echo __BASE_URL; ?>/googlemap.js"> </script>

    </head>
    <body>
        <form method="POST" action="<?php echo $_SERVER['PHP_SELF']; ?>">
            <select id="counties">
                <option value="">Pick a county</option>
            </select>
            <select id="municis" style="display: none;">
            </select>
            <select id="locations" style="display: none;">
            </select>
        </form>
        <div id="map-wrapper">
            <div id="map-canvas"></div>
        </div>

    </body>
</html>