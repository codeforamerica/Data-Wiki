<?php
/**
 * @file
 * community_group_content_type.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function community_group_content_type_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic|node|community_group|form';
  $field_group->group_name = 'group_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_activity',
      1 => 'field_contact',
      2 => 'field_email',
      3 => 'field_url',
      4 => 'field_url_calendar',
      5 => 'title',
      6 => 'group_geographic',
      7 => 'group_metadata',
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
  $export['group_basic|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories_advanced|node|community_group|form';
  $field_group->group_name = 'group_categories_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_categories';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '2',
    'children' => array(
      0 => 'field_term_civic_taxonomy',
      1 => 'field_type_group',
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
  $export['group_categories_advanced|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|community_group|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '2',
    'children' => array(
      0 => 'field_categories',
      1 => 'group_categories_advanced',
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
  $export['group_categories|node|community_group|form'] = $field_group;

/*
  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_community_group|node|community_group|form';
  $field_group->group_name = 'group_community_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Online Community',
    'weight' => '1',
    'children' => array(),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_community_group|node|community_group|form'] = $field_group;
*/

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_geographic|node|community_group|form';
  $field_group->group_name = 'group_geographic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basic';
  $field_group->data = array(
    'label' => 'Map this Group',
    'weight' => '2',
    'children' => array(
      0 => 'field_location',
      1 => 'group_location',
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
  $export['group_geographic|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|node|community_group|default';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '11',
    'children' => array(
      0 => 'group_location',
      1 => 'group_metadata',
      2 => 'group_overview',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_group|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|community_group|default';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Where is this group?',
    'weight' => '13',
    'children' => array(
      0 => 'field_address',
      1 => 'field_area_code',
      2 => 'field_city',
      3 => 'field_district',
      4 => 'field_location_description',
      5 => 'field_neighborhood',
      6 => 'field_region',
      7 => 'field_state',
      8 => 'field_zipcode',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_location|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|community_group|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_geographic';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '16',
    'children' => array(
      0 => 'field_address',
      1 => 'field_area_code',
      2 => 'field_city',
      3 => 'field_district',
      4 => 'field_location_description',
      5 => 'field_neighborhood',
      6 => 'field_region',
      7 => 'field_state',
      8 => 'field_zipcode',
      9 => 'field_location_geocode',
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
  $export['group_location|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|community_group|default';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'More about this group',
    'weight' => '14',
    'children' => array(
      0 => 'field_activity',
      1 => 'field_audience_size',
      2 => 'field_notes',
      3 => 'field_ownership',
      4 => 'field_source',
      5 => 'field_type_group',
      6 => 'field_url_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_metadata|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|community_group|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_basic';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '1',
    'children' => array(
      0 => 'field_audience_size',
      1 => 'field_description',
      2 => 'field_notes',
      3 => 'field_ownership',
      4 => 'field_source',
      5 => 'field_url_image',
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
  $export['group_metadata|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overview|node|community_group|default';
  $field_group->group_name = 'group_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_group';
  $field_group->data = array(
    'label' => 'Overview',
    'weight' => '12',
    'children' => array(
      0 => 'field_categories',
      1 => 'field_contact',
      2 => 'field_description',
      3 => 'field_email',
      4 => 'field_url',
      5 => 'field_url_calendar',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_overview|node|community_group|default'] = $field_group;

  return $export;
}
