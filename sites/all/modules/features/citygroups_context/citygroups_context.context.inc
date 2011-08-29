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
        'citygroups-citygroups_about' => array(
          'module' => 'citygroups',
          'delta' => 'citygroups_about',
          'region' => 'postscript',
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
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'map' => 'map',
        'list' => 'list',
        'about' => 'about',
        'contact' => 'contact',
        'topics' => 'topics',
        'categories' => 'categories',
        'get-involved' => 'get-involved',
        'community-data-api' => 'community-data-api',
        'projects' => 'projects',
        'node/*' => 'node/*',
        'blockwatch' => 'blockwatch',
        'blockwatch*' => 'blockwatch*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-citygroups-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-citygroups-menu',
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
        'menu-menu-postscript-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-postscript-menu',
          'region' => 'postscript',
          'weight' => '10',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer_bottom',
          'weight' => '-21',
        ),
        'citygroups-citygroups_branding_footer' => array(
          'module' => 'citygroups',
          'delta' => 'citygroups_branding_footer',
          'region' => 'footer_bottom',
          'weight' => '-20',
        ),
        'system-powered-by' => array(
          'module' => 'system',
          'delta' => 'powered-by',
          'region' => 'footer_bottom',
          'weight' => '-19',
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
  $context->name = 'dashboard';
  $context->description = '';
  $context->tag = 'admin';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'users/admin' => 'users/admin',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('admin');
  $export['dashboard'] = $context;

  return $export;
}
