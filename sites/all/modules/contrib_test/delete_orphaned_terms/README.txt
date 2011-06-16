
Delete Orphaned Terms
http://drupal.org/project/delete_orphaned_terms
===============================================


DESCRIPTION
-----------
This module provides a way to clean up taxonomy vocabularies, by removing those terms that are no longer referenced by any node (orphans). This action can (optionally) be carried out automatically (cron) according to several parameters.

REQUIREMENTS
------------
- Drupal 6.x
- Taxonomy Module

HISTORY
-------
The initial version of this module was inspired by a discussion on the Drupal Dojo group and borrows from code posted by sapark and lesmana.

The new release from 2010 joins forces with another (uncontributed) module where the initial incentive was to clean up tag based vocabulaires. This module however doesn't restrict you to that, although it gives you the option (see section 'Features'). This was necessary on some pages where people have exposed filters on views where the situation should not occur that they choose a term (in that case: category) that has no items. Surely one might have hacked Views but that would only be the cure to the symptom not to the underlying mess (the orphaned terms).

FEATURES
--------
- manual pruning of specific (or simply all) vocabularies
- automatic pruning with whitelist/blacklist (see below)
- failsafe parameter for automatic mode for all and/or any nodes
- logs to watchdog() if something gets removed (info) or failsafe is triggered (error) (consider using email logging (http://drupal.org/project/logging_alerts))
- simulation of what would be removed (manually or by the automatic job)
- option to only prune tag based vocabularies (this is usually where the biggest mess is)
- option to remove empty vocabularies (dependent on whitelist/blacklist)
- configurable setting of what "orphaned" means
- works with i18n (prunes all languages)

INSTALLING
----------
1. Copy the 'delete_orphaned_terms' folder to your sites/all/modules directory (or a specific site's module directory if you don't want to make it globally available).
2. Go to Administer > Site building > Modules. Enable the module. It appears in the 'Other' category.

DEFAULT CONFIGURATION
---------------------
- automatic job is disabled
- only tag based vocabularies are pruned if the automatic job is enabled
- empty vocabularies are not removed
- terms with zero nodes associated with them are considered orphans, though administrators can specify the number of nodes associated with a term in order for it to be considered an orphan (global setting)
- failsafe at 50%: make sure to tune this to your liking

CONFIGURING AND USING
---------------------
To configure settings go to Administer > Site configuration > Taxonomy Pruner.
To use the manual pruner go to "Delete Orphaned Items" (link at the root of the navigation menu).
Everyone with "Administer Taxonomy" privileges has access to these pages.

WHITELIST AND BLACKLIST LOGIC
-----------------------------
- Term pruning: [YES/NO]

  whitelisted ----> blacklisted ----> is tag (t) ----> tags only (T) ----> [YES]
       |       no        |       no      |         no       |          no  
   yes |             yes |           yes |              yes |
      \_/               \_/             \_/                \_/
     [YES]              [NO]           [YES]               [NO]

  In boolean logic: (w OR (NOT b AND (T => t)))

- Vocabulary pruning: [YES/NO]

            blacklisted ----> is empty (e) ----> [NO]
                 |       no       |         no
             yes |            yes |
                \_/              \_/
               [NO]             [YES]

  In boolean logic: (NOT b AND e)
  (Yes, the whitelist and tag pruning have no meaning here.)

REPORTING ISSUE. REQUESTING SUPPORT. REQUESTING NEW FEATURE
-----------------------------------------------------------
1. Go to the module issue queue at http://drupal.org/project/issues/delete_orphaned_terms?status=All&categories=All
2. Click on CREATE A NEW ISSUE link.
3. Fill the form.
4. To get a status report on your request go to http://drupal.org/project/issues/user

UPGRADING
---------
1. One of the most IMPORTANT things to do BEFORE you upgrade, is to backup your site's files and database. More info: http://drupal.org/node/22281
2. Disable actual module. To do so go to Administer > Site building > Modules. Disable the module.
3. Just overwrite (or replace) the older module folder with the newer version.
4. Enable the new module. To do so go to Administer > Site building > Modules. Enable the module.
5. Run the update script. To do so go to the following address: www.yourwebsite.com/update.php
Follow instructions on screen. You must be log in as an administrator (user #1) to do this step.

Read more about upgrading modules: http://drupal.org/node/250790
