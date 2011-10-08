(function ($) {

Drupal.behaviors.citygroups_base = {
  attach: function (context, settings) {
    $('div#main').prepend('<div class="views-popup  grid_6"><div class="close-button"></div><div class="content"></div></div>'); 
    $('div#main div.views-popup').css('visibility', 'hidden');  
    
    $('div#main div.links div.flag-wrapper').mouseover(function(){
      var flag;
      flag = $(this).html();
      $('div#main div.views-popup div.content').html(flag);
      $('div#main div.views-popup').css('height', '80%');
      $('div#main div.views-popup').css('visibility', 'visible');
    });
    
    $('div#main div.views-popup div.close-button').click(function(){
      $('div#main div.views-popup').css('visibility', 'hidden');
    });    
    
    $('div#main div.node-community-group h2 a').mouseover(function(){
      var group_popup;
      group_popup = $(this).parent().parent().find('div.group-popup').html();
      $('div#main div.views-popup div.content').html(group_popup);
      $('div#main div.views-popup').css('height', '80%');    
    });
  
  }
};

})(jQuery);






    /*
        $('select.form-select', context).once('select.form-select').each(function() {
          $(this).sSelect();
        });
        
    // also: http://robertmarkbramprogrammer.blogspot.com/2010/09/event-handling-with-jquery-autocomplete.html
    */
     // $('div.views-exposed-widgets select.form-select').sSelect();

   // var neighborhoods = [];
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