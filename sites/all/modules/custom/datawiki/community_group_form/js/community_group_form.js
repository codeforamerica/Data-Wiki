document.namespaces;
(function($) {

Drupal.settings.community_group_form = {};
Drupal.behaviors.community_group_form = {};

  var fields = [
    'div.field-name-field-url',
    'div.field-name-field-url-calendar',
    'div.field-name-field-email',
    'div.field-name-field-contact',
    'div.field-name-field-activity',
    'div.field-name-field-notes',
    'div.field-name-field-description',
    'div.field-name-field-source',
    'div.field-name-field-ownership',
    'div.field-name-field-description',
    'div.field-name-field-categories',
  ];
  var description;
  for (var i in fields) {
    // Move the description markup to an interactive element.
    // @TODO a focus css might be a better approach in the long term.
    description = $(fields[i] + ' div.description').html();
    if(description !== null) {
      $(fields[i] + ' div.description').remove();
      $(fields[i] + ' input').after('<div class="description"><div class="close-btn">X</div>' + description + '</div>');
      $(fields[i] + ' div.description').hide();
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