(function ($) {

Drupal.behaviors.citygroups = {
  attach: function (context, settings) {
/*
    $('select.form-select', context).once('select.form-select').each(function() {
      $(this).sSelect();
    });
    
*/
    $('select.form-select').sSelect();
  }
};

})(jQuery);
