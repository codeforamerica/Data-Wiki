document.namespaces;
(function($) {

Drupal.settings.community_group_form = {};

Drupal.behaviors.community_group_form = {
  'attach': function(context, settings) {
    Drupal.settings.community_group_form.data = $('div.openlayers-map').data('openlayers');
    //Drupal.settings.community_group_form.openLayersDrawPoint();
//     Drupal.settings.community_group_form.data.map.width = 400;
    }
  };

  // true/false indication if the label should be moved.
  var fields = {
    'div.field-name-field-url': true,
    'div.field-name-field-url-calendar': true,
    'div.field-name-field-email': true,
    'div.field-name-field-contact': true,
    'div.field-name-field-activity': false,
    'div.field-name-field-notes': false,
    'div.field-name-field-description': false,
    'div.field-name-field-source': true,
    'div.field-name-field-ownership': true,
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
    console.log(field);
    description = $(field + ' div.description').html();
    label =  $(field + ' label').html();
    if(description !== null) {
      $(field + ' div.description').remove();
      $(field + ' input').after('<div class="description"><div class="close-btn">X</div>' + description + '</div>');
      $(field + ' div.description').hide();
      
      if(fields[field]){
        $(field + ' label').remove();
        $(field + ' input').before('<label>' +label + '</label>');
      }

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

 $('div.map-instructions-container div.address-ajax div.submit').click(function () {
   //Drupal.settings.community_group_form.geocodeAddress();
   return false;
 });



var geocoder;
//geocoder = new google.maps.Geocoder();

Drupal.settings.community_group_form.geocodeAddress = function (){
  //  var inputValue = $('div.map-instructions-container div.address-ajax input#search-map-input').val();
    var inputValue = "2025 McGee Ave, Berkeley CA";
    // var googleGeocode = 'http://maps.googleapis.com/maps/api/geocode/json?sensor=false&address=';
    // var geocodeRequest = googleGeocode + inputValue;
    var address = inputValue;
    Drupal.settings.community_group_form.codeAddress(address);
};


Drupal.settings.community_group_form.codeAddress = function(address) {
 var result =  geocoder.geocode( { 'address': address}, function(results, status) {
    if (status == google.maps.GeocoderStatus.OK) {
       Drupal.settings.community_group_form.mapGeocodedData(results);
    } 
    else {
      alert("Geocode was not successful for the following reason: " + status);
    }
  });
  return result;
}

Drupal.settings.community_group_form.mapGeocodedData = function(results) {

  var result = {};
  result.field_address = '';
  console.log(results);
  var item = results[0]['address_components'];
  //console.log(item);
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

 // Drupal.settings.community_group_form.insertGeocodedFieldData(result);
 // Drupal.settings.community_group_form.openLayersDropPoint(result);
};
    
Drupal.settings.community_group_form.insertGeocodedFieldData = function(result) {
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
  
};

Drupal.settings.community_group_form.openLayersDropPoint = function(result){
  // Get map data.
  var data = Drupal.settings.community_group_form.data;
  
  if(result.longitude !== undefined && result.latitude !== undefined) {
    data.openlayers.setCenter(new OpenLayers.LonLat(parseFloat(result.longitude), parseFloat(result.latitude)), 3, false, false);
    //data.openlayers.setCenter(new OpenLayers.LonLat(-122,  37), 3, false, false);
  }
};

})(jQuery);

