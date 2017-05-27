/* 
 * @author     Lars Kristian Dahl <http://www.krisd.com>
 * @copyright  Copyright (c) 2011 Lars Kristian Dahl <http://www.krisd.com>
 * @license    http://www.apache.org/licenses/LICENSE-2.0
 * @version    SVN: $Id$
 */

function initGoogleMap() {
    var norway = new google.maps.LatLng(65, 15);
    var options = {
        zoom: 4,
        center: norway,
        mapTypeId: google.maps.MapTypeId.ROADMAP
    };
    var map = new google.maps.Map(document.getElementById("map-canvas"), options);
    map.markers = {
        counties: [],
        municis: [],
        locations: []
    };
    return map;
}

google.maps.Map.prototype.addMarker = function(arrayname, data) {
    this.markers[arrayname].push(new google.maps.Marker({
        position: new google.maps.LatLng(data.lat, data.lng),
        map: this,
        title: data.title
    }));
}

google.maps.Map.prototype.getMarker = function(arrayname, title) {
    var marker;
    $.each(this.markers[arrayname], function(key, val) {
        if (val.title == title)
            marker = val;
    });
    return marker;
}

google.maps.Map.prototype.clearMarkers = function(arrayname) {
    $.each(this.markers[arrayname], function(key, val) {
        val.setMap(null);
    });
}

google.maps.Map.prototype.clearAllMarkers = function() {
    $.each(this.markers, function(key, markerarray) {
        $.each(markerarray, function(key2, marker) {
            marker.setMap(null);
        });
    });
}