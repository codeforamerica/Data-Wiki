// $Id$
(function ($) {
  Drupal.behaviors.initCityGroupsSplash = {
    attach: function (context, settings) {
      $('.citygroups-splash-link', context).click(function() {
        setTimeout($.colorbox.close, 2000);
      });
    }
  };
})(jQuery);
