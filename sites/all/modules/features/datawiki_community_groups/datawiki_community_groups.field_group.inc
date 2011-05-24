<?php
/**
 * @file
 * datawiki_community_groups.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function datawiki_community_groups_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|node|online_community|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'online_community';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_online_community';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '7',
    'children' => array(
      0 => 'field_url',
      1 => 'field_description',
      2 => 'field_categories',
      3 => 'field_type_web_resource',
      4 => 'field_contact',
      5 => 'field_email',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Basic Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_basic|node|online_community|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_geographic|node|online_community|form';
  $field_group->group_name = 'group_geographic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'online_community';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_online_community';
  $field_group->data = array(
    'label' => 'Geographic',
    'weight' => '10',
    'children' => array(
      0 => 'field_location',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_geographic|node|online_community|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|online_community|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'online_community';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_online_community';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '9',
    'children' => array(
      0 => 'field_area_code',
      1 => 'field_state',
      2 => 'field_neighborhood',
      3 => 'field_city',
      4 => 'field_district',
      5 => 'field_region',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_location|node|online_community|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|online_community|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'online_community';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_online_community';
  $field_group->data = array(
    'label' => 'Say more about this',
    'weight' => '8',
    'children' => array(
      0 => 'field_image',
      1 => 'field_ownership',
      2 => 'field_source',
      3 => 'field_activity',
      4 => 'field_audience_size',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Say more about this',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_metadata|node|online_community|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_online_community|node|online_community|form';
  $field_group->group_name = 'group_online_community';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'online_community';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Online Community',
    'weight' => '5',
    'children' => array(
      0 => 'group_metadata',
      1 => 'group_location',
      2 => 'group_geographic',
      3 => 'group_basic',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_online_community|node|online_community|form'] = $field_group;

  return $export;
}
