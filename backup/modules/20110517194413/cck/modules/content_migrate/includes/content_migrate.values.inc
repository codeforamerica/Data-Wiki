<?php
/**
 * @file content_migrate.values.inc
 * Code to produce D7-style field and instance values from the data in D6 tables.
 * Separated into a separate file for efficiency.
 */
/**
 * Create a D7-style field array from data stored
 * in the D6 content field tables.
 *
 * @param $field_name 
 *   Optionally request only a specific field name.
 */
function _content_migrate_get_field_values($field_name = NULL) {
  $field_values = &drupal_static(__FUNCTION__);
  if (!is_array($field_values)) {
    $field_values = array();
  }
  if (empty($field_values) && db_table_exists('content_node_field')) {
    $field_values = array();
    $query = db_select('content_node_field', 'nf', array('fetch' => PDO::FETCH_ASSOC));
    $node_instance_alias = $query->join('content_node_field_instance', 'ni', 'ni.field_name=nf.field_name');
    $result = $query
      ->fields($node_instance_alias, array('widget_module', 'widget_type', 'widget_settings', 'display_settings'))
      ->fields('nf')
      ->execute();
    
    foreach ($result as $row) {
      $field_value = $row;
    
      // Pass instance settings to the field, in case they are needed.
      $instance_value = array(
        'widget' => array(
          'type' => $row['widget_type'],
          'module' => $row['widget_module'],
          'settings' => unserialize($row['widget_settings']),
        ),
        'display' => array(
           'settings' => unserialize($row['display_settings']),
        ),
      );
      unset($field_value['widget_type'], $field_value['widget_module'], $field_value['widget_settings'], $field_value['display_settings']);
      
      // All Drupal 6 fields were attached to nodes.
      $field_value['entity_types'] = array();
      
      if ($field_value['multiple'] == 0) {
        $field_value['cardinality'] = 1;
      }
      elseif ($field_value['multiple'] == 1) {
        $field_value['cardinality'] = FIELD_CARDINALITY_UNLIMITED;
      }
      else {
        $field_value['cardinality'] = $field_value['multiple'];
      }
      
      // We need column information for the old table.
      $field_value['columns'] = unserialize($field_value['db_columns']);
    
      // Field settings.
      $default_settings = field_info_field_settings($row['type']);
      $field_value['settings'] = array_merge($default_settings, unserialize($field_value['global_settings']));
    
      unset($field_value['multiple'], $field_value['global_settings'], $field_value['required'], $field_value['db_columns']);
            
      // Let modules change these values.
      drupal_alter('content_migrate_field', $field_value, $instance_value);
      
      unset($field_value['allowed_values_php']);
      
      // We retain $field_value['columns'] and $field_value['db_storage']
      // even though they are not used or different in D7 
      // so we can find the old table information.
      
      // Add field definiation to $field_values array.
      $field_values[$field_value['field_name']] = $field_value;
    }
  }
  if (!empty($field_name)) {
    return $field_values[$field_name];
  }
  return $field_values;
}

/**
 * Create a D7-style instance array from data stored
 * in the D6 content field tables.
 *
 * @param $bundle
 *   Optionally request only instances of a specific bundle.
 * @param $field_name
 *   Optionally request only instances of a specific field_name.
 */
function _content_migrate_get_instance_values($bundle = NULL, $field_name = NULL) {
  $instance_values = &drupal_static(__FUNCTION__);
  
  if (empty($instance_values) && db_table_exists('content_node_field_instance')) {
    $instance_values = array();
    $query = db_select('content_node_field_instance', 'ni', array('fetch' => PDO::FETCH_ASSOC));
    $node_field_alias = $query->join('content_node_field', 'nf', 'ni.field_name=nf.field_name');
    $result = $query
      ->fields('ni')
      ->fields($node_field_alias, array('type', 'module', 'required', 'global_settings'))
      ->orderBy('label', 'ASC')
      ->execute();
    
    foreach ($result as $row) { 
      $instance_value = $row;
      
      // Pass field settings to the instance, in case they are needed.
      $field_value = array(
        'require' => $instance_value['required'],
        'type' => $instance_value['type'],
        'module' => $instance_value['module'],
        'settings' => unserialize($instance_value['global_settings']),
      );
      unset($instance_value['type'], $instance_value['module'], $instance_value['required'], $instance_value['global_settings']);      

      // All Drupal 6 instances were attached to nodes.
      $instance_value['entity_type'] = 'node';
    
      // Unserialize arrays.
      foreach (array('widget_settings', 'display_settings', 'global_settings') as $key) {
        $instance_value[$key] = (!empty($instance_value[$key])) ? (array) unserialize($instance_value[$key]) : array();
      }

      // Build instance values.
      $instance_value['bundle'] = $instance_value['type_name'];
      $instance_value['default_value'] = !empty($instance_value['widget_settings']['default_value']) ? $instance_value['widget_settings']['default_value'] : '';
      
      // Core does not support this, but retain it so 
      // another module can do something with it
      // in drupal_alter.
      if (isset($instance_value['widget_settings']['default_value_php'])) {
        $instance_value['widget']['settings']['default_value_php'] = $instance_value['widget_settings']['default_value_php'];
      }

      // Build widget values.
      $instance_value['widget'] = array();
      
      // TODO Some widget types have been renamed in D7.
      $instance_value['widget']['type']     = $instance_value['widget_type'];
      $instance_value['widget']['weight']   = $instance_value['weight'];
      $instance_value['widget']['module']   = $instance_value['widget_module'];
      $instance_value['widget']['active']   = $instance_value['widget_active'];
      
      $default_settings = field_info_widget_settings($field_value['type']);
      $instance_value['widget']['settings'] = array_merge($default_settings, $instance_value['widget_settings']);
    
      // Build display values.
      $instance_value['display'] = array();
      $label = $instance_value['display_settings']['label'];
      foreach ($instance_value['display_settings'] as $context => $settings) {
        if ($context == 'label') {
          continue;
        }
        // @TODO Multigroup fields have some unexpected elements, we need to work out what should happen to them.
        if ($context == 'parent' || $context == 'weight') {
          continue;
        }
        $instance_value['display'][$context]['label'] = $label['format'];
        
        // The format used in D6 may not match the formatter in D7.
        // Fix it using drupal_alter().
        $instance_value['display'][$context]['type'] = $settings['format'];
        $instance_value['display'][$context]['settings'] = field_info_formatter_settings($settings['format']);
        $instance_value['display'][$context]['weight'] = $instance_value['weight'];
        $instance_value['display'][$context]['module'] = $instance_value['widget_module'];

      }
      
      // Unset unneeded values.
      unset($instance_value['type_name'], $instance_value['global_settings'], $instance_value['widget_settings'], $instance_value['display_settings'], $instance_value['widget_module'], $instance_value['widget_active']);
      
      // Unset some values that don't exist on all fields.
      if (isset($instance_value['widget']['settings']['default_value'])) unset($instance_value['widget']['settings']['default_value']);

      // Let modules change these values.
      drupal_alter('content_migrate_instance', $instance_value, $field_value);
      
      // Get rid of this value once CCK or some other module has handled it.
      if (isset($instance_value['widget']['settings']['default_value_php'])) unset($instance_value['widget']['settings']['default_value_php']);

      // Add instance information to instance array.
      $instance_values['instances'][$instance_value['bundle']][$instance_value['field_name']] = $instance_value;
      $instance_values['fields'][$instance_value['field_name']][$instance_value['bundle']] = $instance_value;
      
    }
  }
  if (!empty($bundle)) {
    if (!empty($field_name)) {
      return $instance_values['instances'][$bundle][$field_name];
    }
    else {
      return $instance_values['instances'][$bundle];
    }
  }
  elseif (!empty($field_name)) {
    return $instance_values['fields'][$field_name];
  }
  return $instance_values;
}