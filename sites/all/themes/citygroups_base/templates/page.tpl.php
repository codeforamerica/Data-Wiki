<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 */
?>
<div id="header">
  <div id="header-container" class="container_16">
    <?php if ($page['header_top']): ?>
    <div class="header-top grid_16 alpha omega">
      <?php print render($page['header_top']); ?>
      <div class="clear"></div>
    </div>
    <?php endif; ?>
    <div id="header-middle" class="grid_16 alpha omega">
      <div class="header-logo-container grid_8 alpha">
        <?php print render($logo); ?>
          <div class="clear"></div>
        <?php if($site_slogan): ?>
          <div id="slogan">
            <?php print $site_slogan; ?>
          </div>
        <?php endif; ?> 
      </div>
      <?php if($page['header_search']): ?>       
        <div class="header-search-container grid_4">
          <?php print render($page['header_search']); ?>
        </div>
      <?php endif; ?>
      <div class="header-signin-container grid_3 push_1 omega">
        <?php print render($page['header_signin']); ?>
        <?php print $account_link; ?>
      </div>
    </div>
    <?php if ($page['header_bottom'] || $page['header_menu'] ): ?>
    <div class="clear"></div>
    <div class="header-bottom grid_16 alpha omega">
      <div class="header-menu-container">
        <?php print render($page['header_menu']); ?>
      </div>
      <div class="clear"></div>
      <?php print render($page['header_bottom']); ?>
    </div>
    <?php endif; ?>
  </div>
</div>
<div class="clear"></div>
<div id="main-container" class="container_16">
  <div id="main" role="main" class="grid_16 alpha omega">
    <div class="preface-container grid_8 omega">
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
    <div id="main-content-container" class="grid_16 alpha omega">
      <?php if(!empty($page['sidebar_first'])): ?>
      <div class="sidebar-first-container grid_5 omega">
        <?php print render($page['sidebar_first']); ?>
      </div>
      <?php endif; ?>
      <div class="main-content-region <?php print $main_region_width; ?>">
        <div class="tabs-container grid_11 alpha omega">
          <?php print render($tabs); ?>
        </div>
        <div class="clear"></div>      
        <div class="help-container grid_11 alpha omega">
          <?php print render($page['help']); ?>
        </div>
        <div class="clear"></div>       
        <div class="action-links-container grid_11 alpha omega">
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
      <?php if(!empty($page['sidebar_second'])): ?>
      <div class="sidebar-second-container grid_5 omega">
        <?php print render($page['sidebar_second']); ?>
      </div>
      <?php endif; ?>
    </div> 
    <div class="clear"></div>
  </div>
</div>
<div class="clear"></div>

<?php if(!empty($page['postscript'])): ?>
  <div id="postscript-area">
    <div id="postscript-container" class="container_16">
      <?php print render($page['postscript']); ?>
    </div>
  </div>
  <div class="clear"></div>
<?php endif; ?>
 
<div id="footer-container" class="container_16">
  <div id="footer-content" class="grid_16 alpha omega">
      <?php print render($page['footer_top']); ?> 
      <div class="clear"></div> 
      <?php print render($page['footer']); ?>
      <div class="clear"></div>
      <?php print render($page['footer_bottom']); ?>
      <div class="clear"></div>
  </div>
</div>
<div class="clear"></div>
<?php print $closure ?> 