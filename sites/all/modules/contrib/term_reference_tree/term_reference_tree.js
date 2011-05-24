(function($) {
  $(function() {
    // Bind the term expand/contract button to slide toggle the list underneath.
    $('.term-reference-tree-button').click(function() {
      $(this).toggleClass('term-reference-tree-collapsed');
      $(this).siblings('ul').slideToggle('fast');
    });

    // An expand all button (unimplemented)
    /*
    $('.expandbutton').click(function() {
      $(this).siblings('.term-reference-tree-button').trigger('click');
    });
    */


    $('.term-reference-tree').each(function() {
      // On page load, check whether the maximum number of choices is already selected.
      // If so, disable the other options.
      var tree = $(this);
      checkMaxChoices(tree);
      $(this).find('input[type=checkbox]').change(function() {
        checkMaxChoices(tree);
      });

      // On page load, check if the start minimized option is selected.  If so,
      // minimize each tree, except for lists that contain a checked box.   
      if($(this).hasClass('term-reference-tree-start-minimized')) {
        $(this).find('.term-reference-tree-button').each(function() {
          // If no sibling <ul>'s contain a checked checkbox, add the
          // term-reference-tree-collapsed class and hide the <ul>.
          if($(this).siblings('ul').has('input[type=checkbox]:checked').size() == 0) {
            $(this).addClass('term-reference-tree-collapsed');
            $(this).siblings('ul').hide();
          }
        });
      }
    });
  });

  // This helper function checks if the maximum number of choices is already selected.
  // If so, it disables all the other options.  If not, it enables them.
  function checkMaxChoices(item) {
    var maxChoices = item.attr('data-max-choices');
    var count = item.find(':checked').length;
    
    if(maxChoices > 0 && count >= maxChoices) {
      item.find('input[type=checkbox]:not(:checked)').attr('disabled', 'disabled').parent().addClass('disabled');
    } else {
      item.find('input[type=checkbox]').removeAttr('disabled').parent().removeClass('disabled');
    }
  }
})(jQuery);