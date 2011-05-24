<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */
?>

<div id="container" class="container_16">
  <div id="header" class="grid_16 alpha">
    <div class="header-logo-container grid_4 alpha">
      <?php  print '<a href="' . base_path() . '">' . $site_name . '</a>'; ?>
      <?php // print $sub_site_name; ?>
      <?php // print $logo_image_link; ?>
    </div>
    
    <div class="header-menu-container grid_8">
      <?php print render($page['header_menu']); ?>
    </div>

    <div class="header-gap-container grid_2">
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