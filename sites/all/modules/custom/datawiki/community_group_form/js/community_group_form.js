document.namespaces;
(function($) {

Drupal.settings.community_group_form = {};

Drupal.behaviors.community_group_form = {
  'attach': function(context, settings) {
      Drupal.settings.community_group_form.data = $('div.openlayers-map').data('openlayers');
      Drupal.settings.community_group_form.centerOnFeature();
      
      // @TODO this is a hack.
      $('div.preface-container').append($('div.add-home-menu'));
    }
  };

  // true/false indication if the label should be moved.
  var fields = {
    'div.field-name-field-url': true,
    'div.field-name-field-url-calendar': true,
    'div.field-name-field-email': true,
    'div.field-name-field-contact': true,
/*     'div.field-name-field-activity': false, */
    'div.field-name-field-notes': false,
    'div.field-name-field-description': false,
    'div.field-name-field-source': true,
    'div.field-name-field-ownership': false,
    'div.field-name-field-url-image': true,
    'div.field-name-field-location-description': false,
    'div.field-name-field-location': true,
    'div.field-name-field-location-address': false,
    'div.field-name-field-location-neighborhood': true,
    'div.field-name-field-location-district': true,
    'div.field-name-field-location-city': true,
    'div.field-name-field-location-state': true,
    'div.field-name-field-location-region': true,
    'div.field-name-field-location-zipcode': true,
    'div.field-name-field-location-area-code': true
    /*     'div.field-name-field-categories': false */
  };
  var description;
  var label;
  for (var field in fields) {
    // Move the description markup to an interactive element.
    // @TODO a focus css might be a better approach in the long term.
    description = $(field + ' div.description').html();
    label =  $(field + ' label').html();
    if(description !== null) {
    
      if(fields[field]){
        $(field + ' label').remove();
        $(field + ' input').before('<label>' + label + '</label>');
      }
    
      $(field + ' div.description').remove();
      $(field + ' input').after('<div class="description"><div class="close-btn"></div>' + description + '</div>');
      $(field + ' div.description').hide();
    }
  }
  // When input is selected, show the tooltip.
  $('div.form-item input').click(function(){
    $(this).parent().find('div.description').show();
  });

  // When description close button is clicked, hide the tooltip.
  $('div.description div.close-btn').click(function() {
    $(this).parent().hide();
  });

  var geocodedAddressResults;
  
  // Autoload existing address.
  $('div.map-instructions-container div.address-ajax input#search-map-input').val($('textarea#edit-field-address-und-0-value').val());
  $('div.map-instructions-container div.address-ajax input.search_btn').click(function () {
  Drupal.settings.community_group_form.geocodeAddress();
  return false;
 });



var geocoder;
geocoder = new google.maps.Geocoder();

Drupal.settings.community_group_form.geocodeAddress = function (){
    var inputValue = $('div.map-instructions-container div.address-ajax input#search-map-input').val();
    console.log(inputValue);
    Drupal.settings.community_group_form.codeAddress(inputValue);
};

Drupal.settings.community_group_form.codeAddress = function(address) {
  var result =  geocoder.geocode( { 'address': address}, function(results, status) {
    if (status == google.maps.GeocoderStatus.OK) {
       Drupal.settings.community_group_form.mapGeocodedData(results);
    } 
    else {
      alert("Unable to find that location. Be sure to enter the City, State or Zipcode along with your address.");
    }
  });
  return result;
}

Drupal.settings.community_group_form.mapGeocodedData = function(results) {
  var result = {};
  result.field_address = '';
  console.log(results);
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
   console.log(results[0]);
   result.latitude = results[0]["geometry"]["location"].lat();
   result.longitude = results[0]["geometry"]["location"].lng();
  }
  Drupal.settings.community_group_form.updateMapForm(result);
};
    
Drupal.settings.community_group_form.updateMapForm = function(result) {
  // @TODO use values from geofield instead (data_form)

  if((result.field_address !== undefined) && (result.field_address !== '')) {
    $('textarea#edit-field-address-und-0-value').val(result.field_address);
  }
  if(result.field_zipcode !== undefined) {
    $('input#edit-field-zipcode-und').val(result.field_zipcode);
  }
  if(result.field_city !== undefined) {
    $('input#edit-field-city-und').val(result.field_city);
  }
  if(result.field_state !== undefined) {
    $('input#edit-field-state-und').val(result.field_state);
  }
  if(result.latitude !== undefined) {
    $('input#geofield_lat').val(result.latitude);
  } 
  if(result.longitude !== undefined) {
    $('input#geofield_lon').val(result.longitude);
  } 
  
  Drupal.settings.community_group_form.openLayersDropPoint(result);
};

Drupal.settings.community_group_form.openLayersDropPoint = function(result){
  // Get map data.
  var data = Drupal.settings.community_group_form.data;
console.log(result);
  if(result.longitude !== undefined && result.latitude !== undefined) {    
    var center = new OpenLayers.LonLat(result.longitude, result.latitude).transform(
            new OpenLayers.Projection('EPSG:4326'),
            new OpenLayers.Projection(data.openlayers.projection.projCode));
    var zoomBlockLevel = 15;
    var zoomMultiBlock = 13;
    
    
    var myStyles = new OpenLayers.StyleMap({
              "default": new OpenLayers.Style({
                  pointRadius: "5", // sized according to type attribute
                  strokeColor: "#333333",
                  fillColor: "#FF9900",
                  strokeWidth: 2,
                  fillOpacity: 0.6
              }),
              "select": new OpenLayers.Style({
                  strokeColor: "#333333",
                  fillColor: "#FF9900",
              })
          });

  var feature = new OpenLayers.Feature.Vector(new OpenLayers.Geometry.Point(result.longitude, result.latitude).transform(
            new OpenLayers.Projection('EPSG:4326'),
            new OpenLayers.Projection(data.openlayers.projection.projCode)));
  var edit_feature_layer = data.openlayers.getLayersByName('Selection Layer')[0];

  for (var i = 0; i < edit_feature_layer.features.length; i++) {
    if (edit_feature_layer.features[i] != feature) {
      edit_feature_layer.features[i].destroy();
    }
  } 
  edit_feature_layer.addFeatures(feature);

  // Store the drawn feature in format compatible with geofield.
  Drupal.settings.community_group_form.setItem(feature);
    
  data.openlayers.setCenter(center, zoomBlockLevel, false, false);
  }
};

Drupal.settings.community_group_form.setItem = function(feature) {
  var data = Drupal.settings.community_group_form.data;
  if (data && data.map.behaviors['openlayers_behavior_geofield']) {
    geom = feature.clone().geometry.transform(
      feature.layer.map.projection,
      new OpenLayers.Projection('EPSG:4326'));
      
    centroid = geom.getCentroid();
    bounds = geom.getBounds();
    feature.layer.map.data_form.wkt.val(geom.toString());
    feature.layer.map.data_form.lat.val(centroid.x);      
    feature.layer.map.data_form.lon.val(centroid.y);
    feature.layer.map.data_form.left.val(bounds.left);
    feature.layer.map.data_form.top.val(bounds.top);
    feature.layer.map.data_form.bottom.val(bounds.bottom);
    feature.layer.map.data_form.right.val(bounds.right);
  }
};

Drupal.settings.community_group_form.centerOnFeature = function() {
  var data = Drupal.settings.community_group_form.data;

  // On load, center on the feature and zoom.
  // @TODO this is ignoring the openlayers preset for some reason. 
  var zoomBlockLevel = 15;
  var zoomMultiBlock = 13;
  
  /*
    var lat = $('input#geofield_lat').val();
    var lon = $('input#geofield_lon').val();
  */

  try {
    // Redraw feature with style.
    var myStyles = new OpenLayers.StyleMap({
                "default": new OpenLayers.Style({
                    pointRadius: "5", // sized according to type attribute
                    strokeColor: "#333333",
                    fillColor: "#666666",
                    strokeWidth: 2,
                    fillOpacity: 0.6
                }),
                "select": new OpenLayers.Style({
                    strokeColor: "#333333",
                    fillColor: "#666666",
                })
            });
    var edit_feature_layer = new OpenLayers.Layer.Vector("edit-feature", {
          styleMap: myStyles
      });
    edit_feature_layer.addFeatures(feature);
    data.openlayers.addLayers([edit_feature_layer]);

    // Center the map on the feature.
    var  geom = feature.clone().geometry.transform(
    feature.layer.map.projection,
    new OpenLayers.Projection('EPSG:4326'));        
    
    centroid = geom.getCentroid();
    var center = new OpenLayers.LonLat(centroid.x, centroid.y).transform(
            new OpenLayers.Projection('EPSG:4326'),
            new OpenLayers.Projection(data.openlayers.projection.projCode));
    data.openlayers.setCenter(center, false, false, false);
    

  }
  catch(e) {
    console.log(e);
  }  
};

})(jQuery);

