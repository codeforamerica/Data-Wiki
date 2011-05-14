<?php
/**
 * @file
 * web_resource.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function web_resource_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|web_resource|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'web_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '8',
    'children' => array(
      0 => 'field_location',
      1 => 'field_neighborhood',
      2 => 'field_district',
      3 => 'field_city',
      4 => 'field_area_code',
      5 => 'field_state',
      6 => 'field_region',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_location|node|web_resource|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|web_resource|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'web_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '7',
    'children' => array(
      0 => 'field_description',
      1 => 'field_categories',
      2 => 'field_image',
      3 => 'field_type_web_resource',
      4 => 'field_ownership',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_metadata|node|web_resource|form'] = $field_group;

  return $export;
}
