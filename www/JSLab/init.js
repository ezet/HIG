/* 
 * @author     Lars Kristian Dahl <http://www.krisd.com>
 * @copyright  Copyright (c) 2011 Lars Kristian Dahl <http://www.krisd.com>
 * @license    http://www.apache.org/licenses/LICENSE-2.0
 * @version    SVN: $Id$
 */

$(document).ready(function() {
    var map = initGoogleMap();
    processCounties(map);
    registerEventHandlers(map);
});

function registerEventHandlers(map) {
    onCountyChange(map);
    onMuniciChange(map);
    onLocationChange(map);
}

function onCountyChange(map) {
    $('#counties').change(function() {
        var countyname = this.options[this.selectedIndex].value;
        if (countyname) {
            map.setCenter(map.getMarker('counties', countyname).position);
            map.clearAllMarkers();
            map.setZoom(6);
            processMunicis(map, countyname);
            $('#locations').hide();
        }
    });
}


function onMuniciChange(map) {
    $('#municis').change(function() {
        var municiname = this.options[this.selectedIndex].value;
        map.setCenter(map.getMarker('municis', municiname).position);
        map.clearAllMarkers();
        map.setZoom(8);
        processLocations(map, municiname);
    });
}

function onLocationChange(map) {
    $('#locations').change(function() {
        var locname = this.options[this.selectedIndex].value;
        var marker = map.getMarker('locations', locname);
        map.clearAllMarkers();
        marker.setMap(map);
        map.setCenter(marker.position);
        map.setZoom(10);
    });
}

function processCounties(map) {
    $.getJSON(_base_url +'/counties.php', function(data) {
        $.each(data, function(key, val) {
            $('#counties').append('<option value"'+val.title+'">'+val.title+'</option>');
            map.addMarker('counties', val);
        });
    });
}

function processMunicis(map, countyname) {
    $('#municis').show().empty();
    $.getJSON(_base_url+'/municipalities.php?', 'county='+countyname, function(data) {
        $.each(data, function(key, val) {
            $('#municis').append('<option value"'+val.title+'">'+val.title+'</option>');
            map.addMarker('municis', val);
        });
    });
}

function processLocations(map, municiname) {
    $('#locations').show().empty();
    $.getJSON(_base_url+'/locations.php?', 'munici='+municiname, function(data) {
        $.each(data, function(key, val) {
            $('#locations').append('<option value"'+val.title+'">'+val.title+'</option>');
            map.addMarker('locations', val);
        });
    });
}