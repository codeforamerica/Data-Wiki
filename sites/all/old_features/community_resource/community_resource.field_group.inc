<?php
/**
 * @file
 * community_resource.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function community_resource_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|community_resource|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '5',
    'children' => array(
      0 => 'field_location',
      1 => 'field_neighborhood',
      2 => 'field_district',
      3 => 'field_city',
      4 => 'field_area_code',
      5 => 'field_state',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_location|node|community_resource|form'] = $field_group;

  return $export;
}
