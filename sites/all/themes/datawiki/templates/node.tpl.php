<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="inner">
    <?php print $user_picture; ?>

    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted || !empty($content['links']['terms'])): ?>
      <div class="meta">
        <?php if ($display_submitted): ?>
          <span class="submitted">
            <?php print t('Added by !username on !date', array('!username' => $name, '!date' => $date)); ?>
          </span>
      <?php endif; ?>

        <?php if (!empty($content['links']['terms'])): ?>
          <div class="terms terms-inline">
            <?php print render($content['links']['terms']); ?>
          </div>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <?php if ($node_top && !$teaser): ?>
    <div id="node-top" class="node-top row nested">
      <div id="node-top-inner" class="node-top-inner inner">
        <?php print $node_top; ?>
      </div><!-- /node-top-inner -->
    </div><!-- /node-top -->
    <?php endif; ?>

    <div class="content grid_12 alpha <?php print $node_content_width; ?>"<?php print $content_attributes; ?>>

        <?php hide($content['field_image']); ?>

      <div class="content-top">
        <?php print render($content['field_image']); ?>
        <?php if(!empty($share)): print $share; endif; ?>
      </div>

      <?php if($node->type == 'project'): ?>
        <?php hide($content['body']); ?>
        <div class="about">
          <?php print render($content['body']); ?>
        </div>
      <?php endif; ?>

      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        print render($content);
      ?>
    </div>


  <?php if($content['links']): ?>
    <div class="links grid_4 omega">
      <?php print render($content['links']); ?>
    </div>
  <?php endif; ?>

  <?php if ($node_sidebar && !$teaser): ?>
    <div id="node-sidebar" class="node-sidebar row nested grid_4 omega">
      <div id="node-sidebar-inner" class="node-sidebar-inner inner">
        <?php print $node_sidebar; ?>
      </div><!-- /node-sidebar-inner -->
    </div><!-- /node-sidebar -->
    <div class="clear"></div>
  <?php endif; ?>


    <div class="clear"></div>
    <?php print render($content['comments']); ?>
    <div class="clear"></div>
  </div><!-- /inner -->

  <?php if ($node_bottom && !$teaser): ?>
  <div id="node-bottom" class="node-bottom row nested">
    <div id="node-bottom-inner" class="node-bottom-inner inner">
      <?php print $node_bottom; ?>
    </div><!-- /node-bottom-inner -->
  </div><!-- /node-bottom -->
  <?php endif; ?>
</div>
