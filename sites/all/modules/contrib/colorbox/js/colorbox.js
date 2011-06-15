// $Id: colorbox.js,v 1.7.2.3 2010/11/29 09:42:05 frjo Exp $
(function ($) {

Drupal.behaviors.initColorbox = {
  attach: function (context, settings) {
    $('a, area, input', context)
      .filter('.colorbox')
      .once('init-colorbox-processed')
      .colorbox(settings.colorbox);
  }
};

{
  $(document).bind('cbox_complete', function () {
    Drupal.attachBehaviors('#cboxLoadedContent');
  });
}

})(jQuery);
