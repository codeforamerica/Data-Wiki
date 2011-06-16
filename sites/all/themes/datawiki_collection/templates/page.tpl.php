<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */
?>

<div id="container" class="container_16">
    <?php if ($page['header_top']): ?>
    <div class="header-top grid_16">
      <?php print render($page['header_top']); ?>
      <div class="clear"></div>
    </div>
    <?php endif; ?>
    <div id="header" class="grid_16">
      <div class="header-logo-container grid_4 alpha">
        <?php print render($page['header_logo']); ?>
        <?php print $sitename; ?>
      </div>
      
      <div class="header-menu-container grid_2">
        <?php print render($page['header_menu']); ?>
      </div>
  
      <div class="header-signin-container grid_4">
        <?php print render($page['header_signin']); ?>
        <?php print $account_link; ?>
      </div>
  
      <div class="header-gap-container grid_6 omega">
        <?php print render($page['header_gap']); ?>
      </div>
    </div>
    <div id="tagline">
      <?php print $tagline; ?>
    </div>
    <div class="clear"></div>
    <?php if ($page['header_bottom']): ?>
    <div class="clear"></div>
    <div class="header-bottom grid_16 omega">
      <?php print render($page['header_bottom']); ?>
    </div>
    <?php endif; ?>
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
     test <div class="tabs-container">
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
      <div id="content-container">
        <?php if ($page['content_top']): ?>
          <div id="content-content-top" class="content-content-top">
            <?php print render($page['content_top']); ?>
          </div>
        <?php endif; ?>
        
        <div class="clear"></div>                      
        <?php if ($page['content']): ?>
          <div id="content-content" class="content-content">
            <?php print render($page['content']); ?>
          </div>
        <?php endif; ?>
  
        <div class="clear"></div>                      
        <?php if ($page['content_bottom']): ?>
          <div id="content-content-bottom" class="content-content-bottom">
            <?php print render($page['content_bottom']); ?>
          </div>
        <?php endif; ?>
      </div>
    </div>

    <div class="sidebar-container grid_4 push_1 omega">
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
      <?php print render($page['footer_top']); ?> 
      <div class="clear"></div> 
      <?php print render($page['footer']); ?>
      <div class="clear"></div>
      <?php print render($page['footer']); ?>
      <div class="clear"></div>
  </div>
  <div class="clear"></div>
</div>