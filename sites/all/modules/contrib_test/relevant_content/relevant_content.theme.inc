<?php


function theme_relevant_content_field_formatter_general($variables) {
  // Get the element from the variables
  $element = $variables['element']['element'];

  // If there are no items, return nothing. Anything else risks empty fields
  if (empty($element['items']['#item'])) return;

  // Get the type from the variables
  $type = $variables['type'];

  // We only need this bit for token_* formatters
  if ($type == 'token_full' || $type == 'token_teaser') {
    // Get the token_full settings and make sure they're plain (this is important)
    $token_pattern = check_markup($element['#settings']['#item'][$type]['body'], $element['#settings']['#item'][$type]['format']);
  }

  // Init the output, count and num item variables
  $output = '';
  $count = 0;
  $num_items = count($element['items']['#item']);

  // Loop over all the items and create the field output
  foreach ($element['items']['#item'] as $item) {
    $attributes = array('class' => 'field-item ' . ($count % 2 ? 'even' : 'odd'));

    // Append a "first" class to the row
    if ($count == 0) {
      $attributes['class'] .= ' first';
    }

    // Append a "last" class to the row
    if ($count == $num_items - 1) {
      $attributes['class'] .= ' last';
    }

    // Depending on the type, render a field
    switch ($type) {
      default:
      case 'default' :
        $result = l($item['title'], 'node/'. $item['nid']);
        break;

      case 'plain' :
        $result = check_plain($item['title']);
        break;

      case 'teaser' :
      case 'full' :
        $result = drupal_render(node_build(node_load($item['nid']), $type));
        break;

      case 'token_full' :
      case 'token_teaser' :
        // Run a token replace on the content
        $types = array('global' => NULL, 'node' => node_load($item['nid']));
        $result = token_replace($token_pattern, $types);
        break;
    }

    // Generate the field
    $output .= theme('relevant_content_individual_field', array('attributes' => $attributes, 'result' => $result));
    //$output .= '<div'. drupal_attributes($attributes) .'>'. $result .'</div>';
    $count++;
  }

  // Wrap the result in a field-items wrapper to make it content-field.tpl.php consistent
  return '<div class="field-items">'. $output .'</div>';
}


/**
 *  Theme wrapper for output of individual fields.
 */
function theme_relevant_content_individual_field($variables) {
  return '<div'. drupal_attributes($variables['attributes']) .'>'. $variables['result'] .'</div>';
}

/**
 * Default formatter - hyperlinked nodes
 */
function theme_field_formatter_relevant_content_default($element) {
  return theme('relevant_content_field_formatter_general', array('element' => $element, 'type' => 'default'));
}


/**
 * Optional formatter - plain text nodes
 */
function theme_field_formatter_relevant_content_plain($element) {
  return theme('relevant_content_field_formatter_general', array('element' => $element, 'type' => 'plain'));
}


/**
 * Optional formatter - teaser nodes
 */
function theme_field_formatter_relevant_content_teaser($element) {
  return theme('relevant_content_field_formatter_general', array('element' => $element, 'type' => 'teaser'));
}


/**
 * Optional formatter - full nodes
 */
function theme_field_formatter_relevant_content_full($element) {
  return theme('relevant_content_field_formatter_general', array('element' => $element, 'type' => 'full'));
}


/**
 * Optional formatter - Token "teaser" field
 */
function theme_field_formatter_relevant_content_token_teaser($element) {
  return theme('relevant_content_field_formatter_general', array('element' => $element, 'type' => 'token_teaser'));
}


/**
 * Optional formatter - Token "full" field
 */
function theme_field_formatter_relevant_content_token_full($element) {
  return theme('relevant_content_field_formatter_general', array('element' => $element, 'type' => 'token_full'));
}


/**
 * Theme function for rendering the relevant nodes into a block.
 *
 * This is provided as an item list by default, however a themer can
 * easily override this to make a teaser list or table.
 *
 * Each item will default to a hyperlink to the node unless the token pattern is set.
 *
 * @param $nodes
 *   Associative array where the key is the node id and the value is the node title
 * @param $header
 *   Optional string to display at the top of the block
 */
function theme_relevant_content_block($variables) {
  $settings = variable_get('relevant_content', array());

  // Default to "link" type
  $type = 'link';

  // If we have a delta (we should - only 3rd party legacy code should cause us not to) then get the settings and token settings.
  // Also check tokens is enabled. Its optional
  if (isset($variables['delta']) && isset($settings[$variables['delta']])) {
    // Cleanup the token pattern
    $token_pattern = trim($settings[$variables['delta']]['token_settings']);

    // If the token pattern is not empty, switch to tokens mode
    if (!empty($token_pattern)) {
      $type = 'tokens';
    }
  }

  $items = array();
  foreach ($variables['nodes'] as $node) {
    // If we're a link, default to a hyperlink - otherwise we should use tokens.
    switch ($type) {
      default :
      case 'link' :
        $items[] = l($node['title'], 'node/'. $node['nid']);
        break;

      case 'tokens' :
        $objects = array('global' => NULL, 'node' => node_load($node['nid']));
        $items[] = token_replace($token_pattern, $objects);
        break;
    }
  }

  $output = '';
  if ($variables['header']) {
    $output = check_markup($variables['header']);
  }

  $output .= theme('item_list', array('items' => $items));
  return $output;
}


/**
 * An internal theme function to render the tokens to help the user. NOTE: Why is this not a core theme function?!
 */
function theme_relevant_content_token_help() {
  $token_info = token_info();
  $output = '<p>'. t('Available tokens are:') .'</p>';
  $output .= '<dl>';
  foreach(array('node', 'site', 'date') as $key) {
    $output .= "<dt><strong>{$token_info['types'][$key]['name']}</strong> - {$token_info['types'][$key]['description']}</dt>";
    $token_pairs = array();
    foreach ($token_info['tokens'][$key] as $token => $info) {
      $token_pairs[] = "<code>[{$key}:{$token}]</code> - {$info['name']}";
    }
    $output .= '<dd>'. theme('item_list', array('items' => $token_pairs)) .'</dd>';
  }
  $output .= '</dl>';

  return $output;
}
