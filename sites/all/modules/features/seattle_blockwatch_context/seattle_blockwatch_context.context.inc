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
        'blockwatch-finder*' => 'blockwatch-finder*',
        'blockwatch-finder/*' => 'blockwatch-finder/*',
      ),
    ),
  );
  $context->reactions = array(
    'theme' => array(
      'title' => 'Blockwatch Finder',
      'subtitle' => 'A public directory of blockwatches in Seattle.',
    ),
    'theme_html' => array(
      'class' => 'blockwatch-finder',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('datawiki');
  $export['seattle_blockwatch_context'] = $context;

  return $export;
}
