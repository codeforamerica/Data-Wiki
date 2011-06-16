// $Id$
(function ($) {
  Drupal.behaviors.initOpenPublicSplash = {
    attach: function (context, settings) {
      $('.openpublic-splash-link', context).click(function() {
        setTimeout($.colorbox.close, 2000);
      });
    }
  };
})(jQuery);
