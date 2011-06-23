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
  $context->name = 'sea_blockwatch_home';
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
        'sea_blockwatch-sea_blockwatch_about_block' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_about_block',
          'region' => 'sidebar_second',
          'weight' => '-29',
        ),
        'sea_blockwatch-sea_blockwatch_facebook_like' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_facebook_like',
          'region' => 'sidebar_second',
          'weight' => '-28',
        ),
        'sea_blockwatch-sea_blockwatch_search' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_search',
          'region' => 'content',
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
  $export['sea_blockwatch_home'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sea_blockwatch_list';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blockwatch/list' => 'blockwatch/list',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['sea_blockwatch_list'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sea_blockwatch_main';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blockwatch' => 'blockwatch',
        'blockwatch/map' => 'blockwatch/map',
        'blockwatch/list' => 'blockwatch/list',
        'blockwatch/topics' => 'blockwatch/topics',
        'blockwatch/about' => 'blockwatch/about',
        'blockwatch/contact' => 'blockwatch/contact',
        'blockwatch/add' => 'blockwatch/add',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['sea_blockwatch_main'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sea_blockwatch_map';
  $context->description = '';
  $context->tag = 'datawiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blockwatch/map' => 'blockwatch/map',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'sea_blockwatch-sea_blockwatch_map' => array(
          'module' => 'sea_blockwatch',
          'delta' => 'sea_blockwatch_map',
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
  $export['sea_blockwatch_map'] = $context;

  return $export;
}
