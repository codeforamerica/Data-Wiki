(function ($) {

Drupal.behaviors.citygroups = {
  attach: function (context, settings) {
    //console.log("test");
  }
  
  
  
  
/**
 * This script transforms a set of fieldsets into a stack of vertical
 * tabs. Another tab pane can be selected by clicking on the respective
 * tab.
 *
 * Each tab may have a summary which can be updated by another
 * script. For that to work, each fieldset has an associated
 * 'verticalTabCallback' (with jQuery.data() attached to the fieldset),
 * which is called every time the user performs an update to a form
 * element inside the tab pane.
 */
Drupal.behaviors.verticalTabsAlter = {
  attach: function (context) {
    $('div.vertical-tabs').addClass('grid_12');
    console.log("TeST");
  
  }
  
};

})(jQuery);
