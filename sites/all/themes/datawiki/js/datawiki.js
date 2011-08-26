(function ($) {

Drupal.behaviors.citygroups = {
  attach: function (context, settings) {
  
    $('select.form-select').sSelect();

  }
};

})(jQuery);
