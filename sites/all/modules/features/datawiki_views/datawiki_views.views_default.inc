<?php
/**
 * @file
 * datawiki_views.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function datawiki_views_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'data_categories';
  $view->description = 'A JSON feed of Categories';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Data Categories';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Data Categories';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '250';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'categories';
  $handler->display->display_options['style_options']['top_child_object'] = 'term';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 1;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'description';
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'id';
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['tid']['format_plural'] = 0;
  /* Field: Taxonomy term: Image URL */
  $handler->display->display_options['fields']['field_term_image_url']['id'] = 'field_term_image_url';
  $handler->display->display_options['fields']['field_term_image_url']['table'] = 'field_data_field_term_image_url';
  $handler->display->display_options['fields']['field_term_image_url']['field'] = 'field_term_image_url';
  $handler->display->display_options['fields']['field_term_image_url']['label'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_image_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_image_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_term_image_url']['type'] = 'plain';
  $handler->display->display_options['fields']['field_term_image_url']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Weight */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  $handler->display->display_options['fields']['weight']['label'] = 'term_weight';
  $handler->display->display_options['fields']['weight']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['external'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['weight']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['weight']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['html'] = 0;
  $handler->display->display_options['fields']['weight']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['weight']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['weight']['hide_empty'] = 0;
  $handler->display->display_options['fields']['weight']['empty_zero'] = 0;
  $handler->display->display_options['fields']['weight']['hide_alter_empty'] = 0;
  /* Field: Taxonomy vocabulary: Description */
  $handler->display->display_options['fields']['description_1']['id'] = 'description_1';
  $handler->display->display_options['fields']['description_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['description_1']['field'] = 'description';
  $handler->display->display_options['fields']['description_1']['label'] = 'vocabulary_description';
  $handler->display->display_options['fields']['description_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description_1']['hide_alter_empty'] = 0;
  /* Field: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['label'] = 'vocabulary_machine_name';
  $handler->display->display_options['fields']['machine_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['machine_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['machine_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['machine_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['machine_name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['machine_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['machine_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['machine_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['machine_name']['hide_alter_empty'] = 0;
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'vocabulary_name';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 0;
  /* Field: Taxonomy term: Image File */
  $handler->display->display_options['fields']['field_file_image']['id'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['table'] = 'field_data_field_file_image';
  $handler->display->display_options['fields']['field_file_image']['field'] = 'field_file_image';
  $handler->display->display_options['fields']['field_file_image']['label'] = 'image';
  $handler->display->display_options['fields']['field_file_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_file_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_file_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_file_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_file_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_file_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_file_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file_image']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_file_image']['field_api_classes'] = 0;
  /* Field: Taxonomy term: Location */
  $handler->display->display_options['fields']['field_term_location']['id'] = 'field_term_location';
  $handler->display->display_options['fields']['field_term_location']['table'] = 'field_data_field_term_location';
  $handler->display->display_options['fields']['field_term_location']['field'] = 'field_term_location';
  $handler->display->display_options['fields']['field_term_location']['label'] = 'geometry';
  $handler->display->display_options['fields']['field_term_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_term_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_term_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_term_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_term_location']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_term_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_term_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_term_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_term_location']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_term_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_term_location']['type'] = 'geofield_geojson';
  $handler->display->display_options['fields']['field_term_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_term_location']['field_api_classes'] = 0;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'categories' => 'categories',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'categories/json';

  /* Display: Civic Taxonomies */
  $handler = $view->new_display('page', 'Civic Taxonomies', 'page_1');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'categories' => 'categories',
  );
  $handler->display->display_options['path'] = 'civic-taxonomy/json';

  /* Display: Terms */
  $handler = $view->new_display('page', 'Terms', 'page_2');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'all' => 'all',
    'activity_level' => 'activity_level',
    'area_code' => 'area_code',
    'audience_size' => 'audience_size',
    'categories' => 'categories',
    'city' => 'city',
    'civic_taxonomy' => 'civic_taxonomy',
    'district' => 'district',
    'neighborhood' => 'neighborhood',
    'ownership' => 'ownership',
    'region' => 'region',
    'state' => 'state',
    'tags' => 'tags',
    'type_group' => 'type_group',
    'type_dataset' => 'type_dataset',
    'type_of_group' => 'type_of_group',
    'zipcode' => 'zipcode',
  );
  $handler->display->display_options['path'] = 'terms/json';
  $export['data_categories'] = $view;

  return $export;
}
