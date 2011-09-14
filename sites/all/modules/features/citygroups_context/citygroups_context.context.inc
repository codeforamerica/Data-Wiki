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
  $context->name = 'citygroups_home';
  $context->description = '';
  $context->tag = 'citygroups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'welcome' => 'welcome',
        'home' => 'home',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'citygroups-citygroups_welcome' => array(
          'module' => 'citygroups',
          'delta' => 'citygroups_welcome',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'citygroups-citygroups_home_content' => array(
          'module' => 'citygroups',
          'delta' => 'citygroups_home_content',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('citygroups');
  $export['citygroups_home'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'citygroups_main';
  $context->description = 'Sitewide settings for CityGroups';
  $context->tag = 'citygroups';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-citygroups_header' => array(
          'module' => 'menu',
          'delta' => 'citygroups_header',
          'region' => 'header_menu',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header_search',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'menu-citygroups_postscript' => array(
          'module' => 'menu',
          'delta' => 'citygroups_postscript',
          'region' => 'postscript',
          'weight' => '20',
        ),
        'menu-citygroups_footer' => array(
          'module' => 'menu',
          'delta' => 'citygroups_footer',
          'region' => 'footer_bottom',
          'weight' => '-10',
        ),
        'citygroups-citygroups_branding_footer' => array(
          'module' => 'citygroups',
          'delta' => 'citygroups_branding_footer',
          'region' => 'footer_bottom',
          'weight' => '-9',
        ),
        'system-powered-by' => array(
          'module' => 'system',
          'delta' => 'powered-by',
          'region' => 'footer_bottom',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide settings for CityGroups');
  t('citygroups');
  $export['citygroups_main'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'citygroups_sub';
  $context->description = 'blocks for citygroups subpages';
  $context->tag = 'citygroups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'home' => 'home',
        'welcome' => 'welcome',
        'map' => 'map',
        'list' => 'list',
        'categories' => 'categories',
        'node/add/community-group' => 'node/add/community-group',
        'about' => 'about',
        'get-involved' => 'get-involved',
        'community-data' => 'community-data',
        'developers' => 'developers',
        'api' => 'api',
        'admin/dashboard' => 'admin/dashboard',
        'user/*' => 'user/*',
        'admin/*' => 'admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'citygroups-citygroups_about' => array(
          'module' => 'citygroups',
          'delta' => 'citygroups_about',
          'region' => 'postscript',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('blocks for citygroups subpages');
  t('citygroups');
  $export['citygroups_sub'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard_admin';
  $context->description = '';
  $context->tag = 'citygroups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/dashboard' => 'admin/dashboard',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'citygroups_splash-site_config' => array(
          'module' => 'citygroups_splash',
          'delta' => 'site_config',
          'region' => 'content',
          'weight' => '-25',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('citygroups');
  $export['dashboard_admin'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard_authenticated';
  $context->description = '';
  $context->tag = 'citygroups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/dashboard' => 'admin/dashboard',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-community_groups_list-block_1' => array(
          'module' => 'views',
          'delta' => 'community_groups_list-block_1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-dashboard-block' => array(
          'module' => 'views',
          'delta' => 'dashboard-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'citygroups_splash-site_start' => array(
          'module' => 'citygroups_splash',
          'delta' => 'site_start',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('citygroups');
  $export['dashboard_authenticated'] = $context;

  return $export;
}
