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
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '31',
    'children' => array(
      0 => 'field_description',
      1 => 'field_notes',
      2 => 'field_source',
      3 => 'field_url_calendar',
      4 => 'field_url_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Contact information here...',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_basic|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories_advanced|node|community_group|default';
  $field_group->group_name = 'group_categories_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '1',
    'children' => array(
      0 => 'field_location',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'classes' => 'grid_4',
        'description' => '',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_categories_advanced|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories_advanced|node|community_group|form';
  $field_group->group_name = 'group_categories_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'More',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_categories_advanced|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|community_group|default';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '3',
    'children' => array(
      0 => 'field_categories',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Categories',
      'instance_settings' => array(
        'classes' => 'grid_8  push_8 omega',
        'description' => '',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_categories|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|community_group|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '32',
    'children' => array(
      0 => 'field_activity',
      1 => 'field_audience_size',
      2 => 'field_categories',
      3 => 'field_ownership',
      4 => 'field_type_group',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Categories',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Categorize',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_categories|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|community_group|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '30',
    'children' => array(
      0 => 'field_contact',
      1 => 'field_email',
      2 => 'field_url',
      3 => 'title',
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
  $export['group_contact|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|community_group|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Community Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_basic',
      1 => 'group_categories',
      2 => 'group_contact',
      3 => 'group_geographic',
      4 => 'group_prepare',
      5 => 'group_privacy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'label' => 'Community Group',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_details|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_geographic|node|community_group|form';
  $field_group->group_name = 'group_geographic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Map',
    'weight' => '34',
    'children' => array(
      0 => 'field_address',
      1 => 'field_city',
      2 => 'field_location',
      3 => 'field_location_description',
      4 => 'field_neighborhood',
      5 => 'field_state',
      6 => 'field_zipcode',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Map',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Locate the group on the map',
      ),
      'formatter' => 'open',
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
    'label' => 'More',
    'weight' => '5',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_group|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_information|node|community_group|form';
  $field_group->group_name = 'group_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Information',
    'weight' => '6',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_information|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|community_group|default';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '2',
    'children' => array(
      0 => 'field_address',
      1 => 'field_city',
      2 => 'field_county',
      3 => 'field_location_description',
      4 => 'field_neighborhood',
      5 => 'field_state',
      6 => 'field_zipcode',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'classes' => 'grid_4 omega',
        'description' => '',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
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
  $field_group->parent_name = 'group_machines';
  $field_group->data = array(
    'label' => 'More',
    'weight' => '7',
    'children' => array(
      0 => 'field_area_code',
      1 => 'field_county',
      2 => 'field_district',
      3 => 'field_location_geocode',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'More',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_location|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_machines|node|community_group|form';
  $field_group->group_name = 'group_machines';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Machines',
    'weight' => '5',
    'children' => array(
      0 => 'field_demographic',
      1 => 'field_external_id',
      2 => 'field_import_flag_duplicate',
      3 => 'field_import_flag_inactive',
      4 => 'field_import_flag_inappropriate',
      5 => 'field_import_flag_recommended',
      6 => 'field_import_flag_watch',
      7 => 'field_import_uuid',
      8 => 'field_term_civic_taxonomy',
      9 => 'group_location',
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
  $export['group_machines|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|community_group|default';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More',
    'weight' => '4',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'More',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_metadata|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overview|node|community_group|default';
  $field_group->group_name = 'group_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_activity',
      1 => 'field_audience_size',
      2 => 'field_contact',
      3 => 'field_description',
      4 => 'field_notes',
      5 => 'field_ownership',
      6 => 'field_source',
      7 => 'field_type_group',
      8 => 'field_url',
      9 => 'field_url_calendar',
      10 => 'field_url_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Information',
      'instance_settings' => array(
        'classes' => 'grid_8 alpha',
        'description' => '',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_overview|node|community_group|default'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prepare|node|community_group|form';
  $field_group->group_name = 'group_prepare';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Prepare',
    'weight' => '28',
    'children' => array(
      0 => 'field_prepare',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Prepare',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Prepare',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_prepare|node|community_group|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_privacy|node|community_group|form';
  $field_group->group_name = 'group_privacy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Privacy',
    'weight' => '29',
    'children' => array(
      0 => 'field_privacy',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Privacy',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Privacy',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_privacy|node|community_group|form'] = $field_group;

  return $export;
}
