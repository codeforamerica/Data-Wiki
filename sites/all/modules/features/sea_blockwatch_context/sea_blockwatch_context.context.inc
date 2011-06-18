<?php
/**
 * @file
 * sea_blockwatch_context.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function sea_blockwatch_context_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sea_blockwatch_context';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blockwatch' => 'blockwatch',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'sea_blockwatch-sea_blockwatch_search' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_search',
          'region' => 'sidebar_first',
          'weight' => '-32',
        ),
        'sea_blockwatch-sea_blockwatch_about_block' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_about_block',
          'region' => 'sidebar_first',
          'weight' => '-31',
        ),
        'sea_blockwatch-sea_blockwatch_facebook_like' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_facebook_like',
          'region' => 'sidebar_first',
          'weight' => '-30',
        ),
        'sea_blockwatch-sea_blockwatch_home_menu' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_home_menu',
          'region' => 'preface',
          'weight' => '-10',
        ),
        'sea_blockwatch-sea_blockwatch_map' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_map',
          'region' => 'content',
          'weight' => '-9',
        ),
        'sea_blockwatch-sea_blockwatch_add_data' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_add_data',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['sea_blockwatch_context'] = $context;

  return $export;
}
