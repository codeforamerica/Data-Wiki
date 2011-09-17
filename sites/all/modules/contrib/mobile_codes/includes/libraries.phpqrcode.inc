<?php
/**
 * @file
 * PHP QR Code library integration.
 */

/**
 * Implements mobile_codes_libraries_hook_menu_alter().
 */
function mobile_codes_libraries_phpqrcode_menu_alter(&$items) {
  $items['phpqrcode'] = array(
    'title' => 'PHP QR Code',
    'page callback' => 'mobile_codes_libraries_phpqrcode_generate',
    'access callback' => TRUE,
    'type' => MENU_CALLBACK,
  );
}

/**
 * Implements mobile_codes_libraries_hook_default_mobile_codes_provider_alter().
 */
function mobile_codes_libraries_phpqrcode_default_mobile_codes_provider_alter(&$export) {
  global $base_url;

  $provider = new stdClass;
  $provider->disabled = FALSE; /* Edit this to true to make a default provider disabled initially */
  $provider->api_version = 2;
  $provider->name = 'phpqrcode';
  $provider->url = "{$base_url}/phpqrcode?data=[data]&level=[ecc]&size=[size]&margin=[margin]";
  $provider->parameters = array(
    'data' => array(
      'token' => 'data',
      'type' => 'data',
    ),
    'ecc' => array(
      'token' => 'ecc',
      'label' => 'Error correction level',
      'type' => 'select',
      'value' => 'L|L - smallest
M
Q
H|H - best',
    ),
    'size' => array(
      'token' => 'size',
      'label' => 'Size',
      'type' => 'select',
      'value' => '1
2
3
4
5
6
7
8
9
10',
    ),
    'margin' => array(
      'token' => 'margin',
      'label' => 'Margin',
      'type' => 'text',
    ),
  );

  $export['phpqrcode'] = $provider;
}

/**
 *
 */
function mobile_codes_libraries_phpqrcode_generate() {
  require_once libraries_get_path('phpqrcode/qrlib.php');

  header("Content-Type: image/png");
  QRcode::png($_REQUEST['data'], NULL, $_REQUEST['level'], $_REQUEST['size'], $_REQUEST['margin']);
}
