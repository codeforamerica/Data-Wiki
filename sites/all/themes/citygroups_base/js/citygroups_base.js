(function ($) {

Drupal.behaviors.citygroups_base = {
  attach: function (context, settings) {
/*
    $('select.form-select', context).once('select.form-select').each(function() {
      $(this).sSelect();
    });
    
// also: http://robertmarkbramprogrammer.blogspot.com/2010/09/event-handling-with-jquery-autocomplete.html
*/
 // $('div.views-exposed-widgets select.form-select').sSelect();
  
  
  $('div.views-number-results div.label').html('groups');


  var neighborhoods = [];

  // Remove delay from autocomplete.
  Drupal.ACDB = function (uri) {
    this.uri = uri;
    this.delay = 10;
    this.cache = {};
  };

/*
  $('select#edit-field-neighborhood-tid option').each(function(){
    var html = $(this).html();
    var value = $(this).val();
    neighborhoods.push(html);
  });
*/
//console.log(neighborhoods);
/*   $('div.views-exposed-widgets').append('<div class="ui-widget"><div class="neighborhoods-autocomplete">autocomplete</div></div>'); */

/*

		$("div.neighborhoods-autocomplete").autocomplete({
			source: neighborhoods
		});
*/




  }
};

})(jQuery);
