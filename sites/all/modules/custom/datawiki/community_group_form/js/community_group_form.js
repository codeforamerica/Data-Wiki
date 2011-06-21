document.namespaces;
(function($) {

Drupal.settings.community_group_form = {};
Drupal.behaviors.community_group_form = {};

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

 $('div.map-instructions-container div.address-ajax div.submit').click(function () {
   Drupal.settings.community_group_form.geocodeAddress();
 });
 
//32 perry st. stoughton, ma


Drupal.settings.community_group_form.geocodeAddress = function (){
  //http://maps.googleapis.com/maps/api/geocode/json?address=1600+Amphitheatre+Parkway,+Mountain+View,+CA&sensor=true_or_false

    var inputValue = $('div.map-instructions-container div.address-ajax input#search-map-input').val();
/*     inputValue = Drupal.settings.community_group_form.spaceToPlus(inputValue); */
    var googleGeocode = 'http://maps.googleapis.com/maps/api/geocode/json?sensor=false&address=';
    var geocodeRequest = googleGeocode + inputValue;

    var data = inputValue;
    
    $.ajax({
      url: '/add/community-group/geocode',
      dataType: 'json',
      type: 'put',
      data: data,
      success: Drupal.settings.community_group_form.loadGeocodeSuccess,
      error: Drupal.settings.community_group_form.loadDataError
    });    
};

Drupal.settings.community_group_form.loadDataError = function(e) {
  console.log("error");
};
/**
 * Convert spaces in a string to pluses.
 */
Drupal.settings.community_group_form.spaceToPlus = function(val) {
  // @TODO convert spaces to +
  
/*   val = val.replace('/ /g', '\+'); */
  console.log("test");
  console.log(val);
  return val;
};

Drupal.settings.community_group_form.loadGeocodeSuccess = function(data) {
console.log("success");
  console.log(data);

};

Drupal.settings.community_group_form.mapGeocodedData = function(geocodedData) {
  console.log(geocodedData);
  var formObject = {};
  formObject.field_address = "";
  /*
    for (i in geocodedData.results.address_components) {
      switch(geocodedData.results.address_components[i]["types"][0]) {
        case 'street_number':
          formObject.field_address += geocodedData.results.address_components[i]["long_name"] + " ";
          break;
        case 'route':
          formObject.field_address += geocodedData.results.address_components[i]["long_name"];
          break;
        case 'locality':
          formObject.field_city = geocodedData.results.address_components[i]["long_name"];
          break;  
        case 'administrative_area_level_1':
          formObject.field_state = geocodedData.results.address_components[i]["short_name"];
          break;  
        case 'postal_code':
          formObject.field_zipcode = geocodedData.results.address_components[i]["long_name"];
          break;  
      }
    }
  */
  console.log(formObject);
};
    




})(jQuery);

