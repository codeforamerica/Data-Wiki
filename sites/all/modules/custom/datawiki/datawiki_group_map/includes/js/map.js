var cityGroups = {};
cityGroups.map = {};
cityGroups.geoJSON = {};
cityGroups.map.settings = {};
cityGroups.map.rendered;
cityGroups.data = {};
cityGroups.map.form = {};
var datawiki;

var geocodedAddressResults;
var geocoder;


// Custom search paths.
cityGroups.paths = {
    "defaultPath": "/data/community-group/map",
    "#defaultPath": "/data/community-group/map",
};
        
$(document).ready(function() {
  geocoder = new google.maps.Geocoder();
  cityGroups.map.polygonOptions = Drupal.settings.datawiki.mapColors;
  cityGroups.data.popularLoad();
  cityGroups.loadData(cityGroups.paths['defaultPath']);
  cityGroups.mapPageInteractions();
  $('input#search-links-submit').click(function() {
    cityGroups.map.geocodeAddress();
    return false;
  });
});

cityGroups.mapPageInteractions = function () {
  $('ul.menu a#popular-search').click(function() {
/*     $('div#popular-terms').css('backgroundColor', '#bb4433'); */
  });
};

cityGroups.data.popularLoad = function () {
  $('div#popular-terms ul li a').click(function(){ 
/*     var path = cityGroups.paths[$(this).attr('href')]; */
    // Dynamically load the path.
    var path = cityGroups.paths.defaultPath + '/' + $(this).attr('href');
    path = path.replace("#", '');
    if( $(this).attr('href') == '#defaultPath') {
     path = cityGroups.paths['defaultPath'];
    }
    cityGroups.loadData(path);
  });
};

cityGroups.loadData = function(path) {
  if (path === undefined) {
    var path = cityGroups.paths.defaultPath;
  }
  var data = "";

  $.ajax({
    url: path,
    dataType: 'json',
    data: data,
    success: cityGroups.loadDataSuccess,
    error: cityGroups.loadDataError
  });

  return false;
};

cityGroups.loadDataError = function(data) {
  console.log("error");
  return false;
};

cityGroups.loadDataSuccess = function(data) {
  $('div.loading').hide();
  cityGroups.data = data;
  cityGroups.map.loadMap();
  cityGroups.geoJSON(cityGroups.data.nodes);
  return false;
};

cityGroups.map.loadMap = function() {
  // initialize the map on the "map" div with a given center and zoom
  cityGroups.map.settings.zoom = 11;
  cityGroups.map.settings.center = new L.LatLng(47.6061889, -122.3308133);
  // cityGroups.map.settings.center = new L.LatLng(cityGroups.map.settings.latitude, cityGroups.map.settings.longitude);
  if(cityGroups.map.rendered === undefined) {
    cityGroups.map.rendered = new L.Map('map', cityGroups.map.settings.center);
  }
  // create a CloudMade tile layer
  cityGroups.map.cloudmadeUrl = 'http://{s}.tile.cloudmade.com/b59bc8b09cd84af58fcef3019d84e662/997/256/{z}/{x}/{y}.png',
  cityGroups.map.cloudmade = new L.TileLayer(cityGroups.map.cloudmadeUrl, {maxZoom: 18});
  cityGroups.map.rendered.setView(cityGroups.map.settings.center, cityGroups.map.settings.zoom).addLayer(cityGroups.map.cloudmade);
};

cityGroups.clearMarkers = function(marker) {
 
};

cityGroups.geoJSON = function(nodes) {
  var mapObject = [];
  var polygonPoints = [];
  var polygonPoint;
  var features = {};


  for (i in nodes) {
    var locationGeoObj = $.parseJSON(nodes[i]["node"]["location_geo"]);
    if(locationGeoObj.type !== undefined) {
      switch(locationGeoObj.type) {
        case "Point":
          cityGroups.map.popupPoints(nodes);
        break;
        case "Polygon":
          var polygonPoints = Array();
          for (p in locationGeoObj.coordinates[0]) {
            polygonPoint = p;
            polygonPoint = new L.LatLng(parseFloat(locationGeoObj.coordinates[0][p][1]),  parseFloat(locationGeoObj.coordinates[0][p][0]));
            polygonPoints.push(polygonPoint); 
          }
          cityGroups.map.popupPolygons(polygonPoints, nodes);
          // Draw a marker in the center of the Polygon.
          if(nodes[i]["node"]["latitude"] !== undefined) {
            cityGroups.map.popupPoints(nodes);    
          }
        break;
      }
    }
    else {
      if(nodes[i]["node"]["latitude"] !== undefined) {
        cityGroups.map.popupPoints(nodes);    
      }
    }
  }
};

cityGroups.map.popupPoints = function (nodes){
  var node = nodes[i]["node"];
  var marker = "";

  if(node.latitude !== undefined){
    var markerLocation = new L.LatLng(parseFloat(node.latitude), parseFloat(node.longitude));
    // @TODO escape these.
    var customMarkerStyle = {
      iconUrl: Drupal.settings.datawiki.mapMarkerIconUrl,
      shadowUrl: Drupal.settings.datawiki.mapMarkerIconShadowUrl,
      iconSize: new L.Point(Drupal.settings.datawiki.mapMarkerIconPointSize[0], Drupal.settings.datawiki.mapMarkerIconPointSize[1]),
      shadowSize: new L.Point(Drupal.settings.datawiki.mapMarkerIconShadowSize[0], Drupal.settings.datawiki.mapMarkerIconShadowSize[1]),
      iconAnchor: new L.Point(Drupal.settings.datawiki.mapMarkerIconAnchor[0], Drupal.settings.datawiki.mapMarkerIconAnchor[1]),
      popupAnchor: new L.Point(Drupal.settings.datawiki.mapMarkerPopupAnchor[0], Drupal.settings.datawiki.mapMarkerPopupAnchor[1])
    };
    var CustomMarker = L.Icon.extend(customMarkerStyle);
    var customIcon = new CustomMarker(),
    marker = new L.Marker(markerLocation, {icon: customIcon});
    cityGroups.map.rendered.addLayer(marker);

    
  	function onMapClick(e) {
  	  $('div#popup-content div.content').html(cityGroups.map.popupTemplate(node));
  	  console.log("test");
  	}
  	
  	function offMapClick(e) {
      $('div#popup-content div.content').html('Click map to see where the groups are');
  	}
  	
    marker.on('click', onMapClick);
	}
};

cityGroups.map.popupPolygons = function (polygonPoints, nodes){
  var node = nodes[i]["node"];
  var marker = "";
  var polygon = new L.Polygon(polygonPoints, cityGroups.map.polygonOptions);
	var markerLocation = new L.LatLng(-1*parseFloat(node.latitude), -1*parseFloat(node.longitude));
  var customMarkerStyle = {
      iconUrl: Drupal.settings.datawiki.mapMarkerIconUrl,
      shadowUrl: Drupal.settings.datawiki.mapMarkerIconShadowUrl,
      iconSize: new L.Point(Drupal.settings.datawiki.mapMarkerIconPointSize[0], Drupal.settings.datawiki.mapMarkerIconPointSize[1]),
      shadowSize: new L.Point(Drupal.settings.datawiki.mapMarkerIconShadowSize[0], Drupal.settings.datawiki.mapMarkerIconShadowSize[1]),
      iconAnchor: new L.Point(Drupal.settings.datawiki.mapMarkerIconAnchor[0], Drupal.settings.datawiki.mapMarkerIconAnchor[1]),
      popupAnchor: new L.Point(Drupal.settings.datawiki.mapMarkerPopupAnchor[0], Drupal.settings.datawiki.mapMarkerPopupAnchor[1])
    };
  var CustomMarker = L.Icon.extend(customMarkerStyle);
  var customIcon = new CustomMarker(),
  marker = new L.Marker(markerLocation, {icon: customIcon});
  /*   cityGroups.map.rendered.removeLayer(marker); */
  cityGroups.map.rendered.addLayer(marker);
  marker.on('click', onMapClick);
	function onMapClick(e) {
	  $('div#popup-content div.content').html(cityGroups.map.popupTemplate(node));
    cityGroups.map.rendered.addLayer(polygon);
    polygon.on('click', offMapClick);
	}
	
	function offMapClick(e) {
    cityGroups.map.rendered.removeLayer(polygon);	
    $('div#popup-content div.content').html('Click map to see where the groups are');
	}
};

cityGroups.map.popupTemplate = function(node) {
  var output = '<div class="popup-item">';
  output += '<a href="' + node.permalink + '" class="title">' + node.title + '</a>';
  if(node.description !== undefined) {
    output += '<div class="description">' + node.description + '</div>';
  }
  if(node.categories !== undefined) {
    output += '<div class="categories">' + node.categories + '</div>';
  }
  
/*   output += "sign in to edit"; */
  output += '<a href="node/' + node.citygroups_nid + '"  >more</a> ';
  output += '<a href="node/' + node.citygroups_nid + '/edit" >edit</a>';
  output += '</div>';
  return output;
};

cityGroups.map.geocodeAddress = function (){
  var inputValue = $('div#search-places input.form-item').val();
  cityGroups.map.codeAddress(inputValue);
};

cityGroups.map.codeAddress = function(address) {
  var result =  geocoder.geocode( { 'address': address}, function(results, status) {
    if (status == google.maps.GeocoderStatus.OK) {
       cityGroups.map.mapGeocodedData(results);
    } 
    else {
      alert("Geocode was not successful for the following reason: " + status);
    }
  });
  return result;
}

cityGroups.map.mapGeocodedData = function(results) {
  var result = {};
  result.field_address = '';
  var item = results[0]['address_components'];

  for (i in item) {     
    switch(item[i]["types"][0]) {
      case 'street_number':
        result.field_address += item[i]["long_name"] + " ";
        break;
      case 'route':
        result.field_address += item[i]["long_name"];
        break;
      case 'locality':
        result.field_city = item[i]["long_name"];
        break;  
      case 'administrative_area_level_1':
        result.field_state = item[i]["short_name"];
        break;  
      case 'postal_code':
        result.field_zipcode = item[i]["long_name"];
        break;
    }
    
   // map geometry
   result.latitude = results[0]["geometry"]["location"]["Ha"];
   result.longitude = results[0]["geometry"]["location"]["Ia"];  
  }
  if (result.longitude !== undefined && result.latitude !== undefined) {
    var center = new L.LatLng(result.latitude, result.longitude);
    cityGroups.map.rendered.setView(center, cityGroups.map.settings.zoom);
  }
};