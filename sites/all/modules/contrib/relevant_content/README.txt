
This module provides a customizable set of blocks which contain an automated & limited number
of links to nodes that are considered "relevant" to the current node based on how the current
node is tagged under it's taxonomy. The more terms another node has in common with the current
node, the more chance it has at appearing towards the top of the list. If multiple nodes
contain the same number of "terms in common" then the more recent ones appear towards the top
of the list.

The module also supports CCK in the form of a "read only" field. Once this field is added to a
node, it will list the results in the same way the block does. The advantage is that you can
combine the result set with your content in a more seamless way.

A very new feature which has been added to this release of Relevent Content is to override the
output using a token field. This means you are no longer restricted to using simply the node
title as a hyperlink, but instead can form more complicated token-based output (such as, for
example, "[title] written on [d] [month] [yy]").
