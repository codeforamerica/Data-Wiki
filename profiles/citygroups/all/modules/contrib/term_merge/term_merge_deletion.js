Drupal.behaviors.term_merge_delete_deletion = {
  attach: function(context, settings) {

    (function ($) {

      function setFormState() {
        if (!$('#edit-replacement-term-replace').is(':checked')) {
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
      $('#edit-replacement-term-replace').bind('click.replacement-term-replace', setFormState);
      $('#edit-replacement-term').bind('change.replacement-term', setFormState);

      var $createOption = $('#edit-replacement-term option:last');
      $createOption.addClass('new-term');

    })(jQuery);

  }
};
