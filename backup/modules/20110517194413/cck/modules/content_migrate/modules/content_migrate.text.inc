<?php
/**
 * @file content_migrate.text.inc
 * Code to implement hook_content_migrate_field_alter, content_migrate_instance_alter() and content_migrate_data_record_alter()
 * on behalf of the former text module, moved into a separate file for efficiency.
 */

/**
 * Implements hook_content_migrate_field_alter().
 * 
 * Use this to tweak the conversion of field settings
 * from the D6 style to the D7 style for specific
 * situations not handled by basic conversion,
 * as when field types or settings are changed.
 */
function content_migrate_text_field_alter(&$field_value, $instance_value) {
  switch ($field_value['type']) {
    case 'text':

      // Text fields are translatable.      
      $field_value['translatable'] = TRUE;

      // The max_length field can no longer be empty 
      // or it will create a SQL error.
      if (empty($field_value['settings']['max_length'])) {
        $field_value['type'] = 'text_long';
        unset($field_value['settings']['max_length']);
      }

      // Text fields using optionwidgets are
      // now List fields.
      switch ($instance_value['widget']['type']) {
        case 'optionwidgets_buttons':
        case 'optionwidgets_select':
          $field_value['type'] = 'list_text';
          $field_value['module'] = 'list';
          break;

        case 'optionwidgets_onoff':
          $field_value['type'] = 'list_boolean';
          $field_value['module'] = 'list';
          break;

        case 'text_textarea':
        case 'text_textfield':
          break;

      }

      // The allowed values list should now be stored as an array.
      switch ($field_value['type']) {
        case 'list_text':
        case 'list_boolean':
          $allowed_values = array();
          if (!empty($field_value['settings']['allowed_values'])) {
            $allowed_values = content_migrate_extract_allowed_values($field_value['settings']['allowed_values'], $field_value['type']);
          }
          $field_value['settings']['allowed_values'] = $allowed_values;
          break;

      }

      break;
  }

}

/**
 * Implements hook_content_migrate_instance_alter().
 *
 * Use this to tweak the conversion of instance or widget settings
 * from the D6 style to the D7 style for specific
 * situations not handled by basic conversion, as when
 * formatter or widget names or settings are changed.
 */
function content_migrate_text_instance_alter(&$instance_value, $field_value) {
  switch ($field_value['module']) {
    case 'text':

      // The text processing setting got switched from a field setting to an instance setting.
      $instance_value['settings']['text_processing'] = $field_value['settings']['text_processing'];

      // The formatter names changed, all are prefixed
      // with 'text_'.
      foreach ($instance_value['display'] as $context => $settings) {
        $instance_value['display'][$context]['type'] = 'text_'. $settings['type'];
      }
      break;
  }

}
