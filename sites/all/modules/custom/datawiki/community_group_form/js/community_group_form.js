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
    'div.field-name-field-description': true,
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

})(jQuery);