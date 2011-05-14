<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * Custom ones added for this specific theme
 * - 
 * -
 * -
 * -
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>
<div id="container" class="container_16">
  <div id="header" class="grid_16 alpha">
    <div class="header-logo-container grid_4 alpha">
      <?php // print $site_name; ?>
      <?php print $sub_site_name; ?>
      <?php // print $logo_image_link; ?>
    </div>
    
    <div class="header-menu-container grid_6">
      <?php print render($page['header_menu']); ?>
    </div>

    <div class="header-gap-container grid_4">
      <?php print render($page['header_gap']); ?>
    </div>

    <div class="header-signin-container grid_2 omega">
      <?php print render($page['header_signin']); ?>
      <?php print $account_link; ?>
    </div>

  </div>
  <div class="clear"></div>
  <div id="main" role="main" class="grid_16 alpha">
    <div class="preface-container">
      <?php print render($page['preface']); ?>
    </div>
    <div class="clear"></div>
    <div class="messages-container">
      <?php print $messages; ?>
    </div>
    <div class="clear"></div>
    
    <div class="title-container">
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
    </div>
    <div class="clear"></div> 

    <div class="main-content-region <?php print $main_region_width; ?> alpha">
      <div class="tabs-container">
        <?php print render($tabs); ?>
      </div>
      <div class="clear"></div>      
      <div class="help-container">
        <?php print render($page['help']); ?>
      </div>
      <div class="clear"></div>       
      <div class="action-links-container">
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
      </div>
      <div class="clear"></div>                      
      <?php if ($page['content']): ?>
        <div id="content-content" class="content-content">
          <?php print render($page['content']); ?>
        </div>
      <?php endif; ?>
    </div>

    <div class="sidebar-container grid_5 omega">
      <div class="sidebar-first-container">
        <?php print render($page['sidebar_first']); ?>
      </div>
  
      <div class="sidebar-second-container">
        <?php print render($page['sidebar_second']); ?>
      </div>
    </div>
    <div class="clear"></div>
    <div class="postscript-container grid_16 alpha">
      <?php print render($page['postscript']); ?>
    </div>
    <div class="clear"></div>
  </div>
  <div class="clear"></div>
  <div id="footer" class="grid_16 alpha">
    <?php print render($page['footer']); ?>
  </div>
  <div class="clear"></div>
</div>