<?php
/**
 * @file
 * seattle_blockwatch_context.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function seattle_blockwatch_context_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'seattle_blockwatch_context';
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
        'seattle_blockwatch-seattle_blockwatch_new_group_search' => array(
          'module' => 'seattle_blockwatch',
          'delta' => 'seattle_blockwatch_new_group_search',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'seattle_blockwatch-seattle_blockwatch_facebook_like' => array(
          'module' => 'seattle_blockwatch',
          'delta' => 'seattle_blockwatch_facebook_like',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'seattle_blockwatch-seattle_blockwatch_about_block' => array(
          'module' => 'seattle_blockwatch',
          'delta' => 'seattle_blockwatch_about_block',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'seattle_blockwatch-seattle_blockwatch_home_menu' => array(
          'module' => 'seattle_blockwatch',
          'delta' => 'seattle_blockwatch_home_menu',
          'region' => 'content',
          'weight' => '-10',
        ),
        'seattle_blockwatch-seattle_blockwatch_map' => array(
          'module' => 'seattle_blockwatch',
          'delta' => 'seattle_blockwatch_map',
          'region' => 'content',
          'weight' => '-9',
        ),
        'seattle_blockwatch-seattle_blockwatch_add_data' => array(
          'module' => 'seattle_blockwatch',
          'delta' => 'seattle_blockwatch_add_data',
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
  $export['seattle_blockwatch_context'] = $context;

  return $export;
}
