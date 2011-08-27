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
        'citygroups_sub-citygroups_sub_welcome' => array(
          'module' => 'citygroups_sub',
          'delta' => 'citygroups_sub_welcome',
          'region' => 'preface',
          'weight' => '-10',
        ),
        'citygroups_sub-citygroups_sub_home_content' => array(
          'module' => 'citygroups_sub',
          'delta' => 'citygroups_sub_home_content',
          'region' => 'content',
          'weight' => '-10',
        ),
        'citygroups_sub-citygroups_sub_about' => array(
          'module' => 'citygroups_sub',
          'delta' => 'citygroups_sub_about',
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
  $context->name = 'dashboard';
  $context->description = '';
  $context->tag = 'citygroups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'users/admin' => 'users/admin',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'citygroups_sub-citygroups_sub_home_menu' => array(
          'module' => 'citygroups_sub',
          'delta' => 'citygroups_sub_home_menu',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'citygroups-citygroups_dashboard_add_content' => array(
          'module' => 'citygroups',
          'delta' => 'citygroups_dashboard_add_content',
          'region' => 'content_top',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('citygroups');
  $export['dashboard'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'citygroups_main';
  $context->description = '';
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
        '~node/add/*' => '~node/add/*',
        '~node/*/edit' => '~node/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header_search',
          'weight' => '-10',
        ),
        'menu-menu-citygroups-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-citygroups-menu',
          'region' => 'header_bottom',
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
          'weight' => '-10',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer_bottom',
          'weight' => '-10',
        ),
        'citygroups_sub-citygroups_sub_branding_footer' => array(
          'module' => 'citygroups_sub',
          'delta' => 'citygroups_sub_branding_footer',
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
  t('citygroups');
  $export['citygroups_main'] = $context;

  return $export;
}
