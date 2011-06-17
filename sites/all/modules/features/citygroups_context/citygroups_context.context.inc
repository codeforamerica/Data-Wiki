<?php
/**
 * @file
 * citygroups_context.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function citygroups_context_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'collection_about';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about/collection/termname' => 'about/collection/termname',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'datawiki_collection-datawiki_collection_branding_header' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_branding_header',
          'region' => 'header_gap',
          'weight' => '-10',
        ),
        'datawiki_collection-datawiki_collection_site_tagline' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_site_tagline',
          'region' => 'header_gap',
          'weight' => '-10',
        ),
/*
        'block-1' => array(
          'module' => 'block',
          'delta' => 1,
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
*/
        'datawiki_collection-datawiki_collection_new_group_search' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_new_group_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'datawiki_collection-datawiki_collection_add_data' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_add_data',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'datawiki_collection-datawiki_collection_welcome' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_welcome',
          'region' => 'content',
          'weight' => '-10',
        ),
        'datawiki_collection-datawiki_collection_facebook_like' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_facebook_like',
          'region' => 'content',
          'weight' => '-10',
        ),
        'datawiki_collection-datawiki_collection_branding_footer' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_branding_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['collection_about'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'collection_categories';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'categories/collection/termname' => 'categories/collection/termname',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'datawiki_collection-datawiki_collection_categories' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_categories',
          'region' => 'content',
          'weight' => '-10',
        ),
        'datawiki_collection-datawiki_collection_categories_menu' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_categories_menu',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['collection_categories'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'collection_home';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'collection/termname' => 'collection/termname',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'datawiki_collection-datawiki_collection_facebook_like' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_facebook_like',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'datawiki_collection-datawiki_collection_welcome' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_welcome',
          'region' => 'content',
          'weight' => '-10',
        ),
        'datawiki_collection-datawiki_collection_home_menu' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_home_menu',
          'region' => 'content',
          'weight' => '-9',
        ),
        'datawiki_collection-datawiki_collection_add_data' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_add_data',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['collection_home'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'collection_list';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'list/collection/termname' => 'list/collection/termname',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'datawiki_collection-datawiki_collection_list' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_list',
          'region' => 'content',
          'weight' => '-10',
        ),
        'datawiki_collection-datawiki_collection_list_menu' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_list_menu',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['collection_list'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'collection_map';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'map/collection/termname' => 'map/collection/termname',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'datawiki_collection-datawiki_collection_map_menu' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_map_menu',
          'region' => 'content',
          'weight' => '-10',
        ),
        'datawiki_collection-datawiki_collection_map' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_map',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['collection_map'] = $context;

  return $export;
}
