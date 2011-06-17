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
        'blockwatch-finder' => 'blockwatch-finder',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'datawiki_collection-datawiki_facebook_like' => array(
          'module' => 'datawiki_collection',
          'delta' => 'datawiki_facebook_like',
          'region' => 'sidebar_first',
          'weight' => '-30',
        ),
        'seattle_blockwatch-seattle_blockwatch_about_block' => array(
          'module' => 'seattle_blockwatch',
          'delta' => 'seattle_blockwatch_about_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'seattle_blockwatch-seattle_blockwatch_home_menu' => array(
          'module' => 'seattle_blockwatch',
          'delta' => 'seattle_blockwatch_home_menu',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'seattle_blockwatch-seattle_blockwatch_welcome' => array(
          'module' => 'seattle_blockwatch',
          'delta' => 'seattle_blockwatch_welcome',
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
