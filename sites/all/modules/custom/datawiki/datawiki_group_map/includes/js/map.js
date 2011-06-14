var cityGroups = {};
cityGroups.map = {};
cityGroups.geoJSON = {};
cityGroups.map.settings = {};
cityGroups.map.rendered;

cityGroups.map.polygonOptions = {
    color: 'red',
    fillColor: '#f03',
    fillOpacity: 0.5
};
        
$(document).ready(function() {
  cityGroups.loadData();
});


cityGroups.loadData = function() {
/*   var dataPath = "http://localhost/codeforamerica/citygroups/citygroups_map/data/community-groups-data.json"; */
var dataPath = "community-groups-data";
/*   var dataPath = "sites/all/modules/custom/datawiki/datawiki_group_map/includes/data/community-groups-data.json"; */
  var data = "";

  $.ajax({
    url: dataPath,
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
  console.log("success!");
  cityGroups.data = data;
  cityGroups.map.loadMap();
  cityGroups.geoJSON(cityGroups.data.nodes);
  return false;
};

cityGroups.geoJSON = function(nodes) {
  var mapObject = [];
  var polygonPoints = [];
  var polygonPoint;
  var features = {};

  for (i in nodes) {
    var locationGeoObj = $.parseJSON(nodes[i]["node"]["location_geo"]);
    console.log(locationGeoObj.type);
    switch(locationGeoObj.type) {
      case "Point":
        cityGroups.map.popupPoints(nodes);
      break;
      case "Polygon":
        var polygonPoints = Array();

        for (p in locationGeoObj.coordinates[0]) {
          polygonPoint = p;
          polygonPoint = new L.LatLng(locationGeoObj.coordinates[0][p][1], locationGeoObj.coordinates[0][p][0]);
          polygonPoints.push(polygonPoint);

        }
        cityGroups.map.popupPolygons(polygonPoints, nodes);
      break;
    }
    if(nodes[i]["node"]["latitude"] !== undefined) {
        cityGroups.map.popupPoints(nodes);    
    }
  }
};

cityGroups.map.popupPoints   = function (nodes){
  var node = nodes[i]["node"];
  if(node.latitude !== undefined){
  	var markerLocation = new L.LatLng(node.latitude, node.longitude);
    var marker = new L.Marker(markerLocation);
    cityGroups.map.rendered.addLayer(marker);
    marker.on('click', onMapClick);
  	function onMapClick(e) {
  	  $('div#popup-content div.content').html(node.title);
      cityGroups.map.rendered.addLayer(polygon);
  	}
  	
  	function offMapClick(e) {
      $('div#popup-content div.content').html('Click map to see where the groups are');
  	}
	}
};

cityGroups.map.popupPolygons = function (polygonPoints, nodes){
  var node = nodes[i]["node"];
  var polygon = new L.Polygon(polygonPoints, cityGroups.map.polygonOptions);
	var markerLocation = new L.LatLng(-1*node.latitude, -1*node.longitude);

  var marker = new L.Marker(markerLocation);
  cityGroups.map.rendered.addLayer(marker);
  marker.on('click', onMapClick);

	function onMapClick(e) {
	  $('div#popup-content div.content').html(node.title);
    cityGroups.map.rendered.addLayer(polygon);
    polygon.on('click',offMapClick);
	}
	
	function offMapClick(e) {
    cityGroups.map.rendered.removeLayer(polygon);	
    $('div#popup-content div.content').html('Click map to see where the groups are');
	}
};

cityGroups.map.loadMap = function() {
  // initialize the map on the "map" div with a given center and zoom
  cityGroups.map.settings.zoom = 11;
  cityGroups.map.settings.center = new L.LatLng(47.6061889, -122.3308133);
  // cityGroups.map.settings.center = new L.LatLng(cityGroups.map.settings.latitude, cityGroups.map.settings.longitude);

  cityGroups.map.rendered = new L.Map('map', cityGroups.map.settings.center);

  // create a CloudMade tile layer
  cityGroups.map.cloudmadeUrl = 'http://{s}.tile.cloudmade.com/b59bc8b09cd84af58fcef3019d84e662/997/256/{z}/{x}/{y}.png',
  cityGroups.map.cloudmade = new L.TileLayer(cityGroups.map.cloudmadeUrl, {maxZoom: 18});
  cityGroups.map.rendered.setView(cityGroups.map.settings.center, cityGroups.map.settings.zoom).addLayer(cityGroups.map.cloudmade);
};