// $Id: colorbox_login.js,v 1.5.2.2 2010/12/03 08:58:34 frjo Exp $
(function ($) {

Drupal.behaviors.initColorboxLogin = {
  attach: function (context, settings) {
    $("a[href*='/user/login'], a[href*='?q=user/login']", context).once('init-colorbox-login-processed', function () {
      this.href = this.href.replace(/user\/login/,"user/login/colorbox");
    }).colorbox({
      initialWidth:200,
      initialHeight:200,
      onComplete:function(){
        $('#edit-name').focus();
      }
    });
  }
};

})(jQuery);
