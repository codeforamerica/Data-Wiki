Drupal.behaviors.term_merge = {
  attach: function(context, settings) {

    (function ($) {

      function setFormState() {
        //alert($('#edit-term-list').val() != null);

        if ($('#edit-term-list').val() == null) {
          setElementEnabledState($('#edit-replacement-term'), false);
          setElementEnabledState($('#edit-replacement-term-new'), false);
        } else if ($('#edit-replacement-term').val() != '0') {
          setElementEnabledState($('#edit-replacement-term'), true);
          setElementEnabledState($('#edit-replacement-term-new'), false);
        } else {
          setElementEnabledState($('#edit-replacement-term'), true);
          setElementEnabledState($('#edit-replacement-term-new'), true);
        }
      }

      function setElementEnabledState($element, enabled) {
        if (enabled) {
          $element.removeAttr('disabled');
          $element.parents('div.form-item').removeClass('disabled');
        } else {
          $element.attr('disabled', true);
          $element.parents('div.form-item').addClass('disabled');
        }
      }

      setFormState();
      $('#edit-term-list').bind('change', setFormState);
      $('#edit-replacement-term').bind('change', setFormState);

      var $createOption = $('#edit-replacement-term option:last');
      $createOption.addClass('new-term');

    })(jQuery);

  }
};
