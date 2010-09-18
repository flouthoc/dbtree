#include <stdlib.h>
#include "dbtree.h"

void *dbtree_store(dbtree *tree, const char *key, void *value) {
    while (1) {
	while (tree->c != *key && tree->sibling != NULL)
	    tree = tree->sibling;
	if (tree->c == *key && *key > 0)
	    tree = tree->child;
	else if (tree->c == *key)
	    return tree->child = value;
	else {
	    dbtree *new = malloc(sizeof(dbtree));
	    new->c = *key;
	    tree = tree->sibling = new;
	    while (*key++ != 0) {
		new = malloc(sizeof(dbtree));
		new->c = *key;
		tree = tree->child = new;
	    }
	    return tree->child = value;
	}
	key++;
    }
}

void *dbtree_fetch(dbtree *tree, const char *key) {
    while (1) {
	while (tree->c != *key && tree->sibling != NULL)
	    tree = tree->sibling;
	if (tree->c == *key && *key > 0)
	    tree = tree->child;
	else if (tree->c == *key)
	    return tree->child;
	else
	    return NULL;
	key++;
    }
}

int dbtree_remove(dbtree *tree, const char *key) {
    while (1) {
	while (tree->c != *key && tree->sibling != NULL)
	    tree = tree->sibling;
	if (tree->c == *key && *key > 0)
	    tree = tree->child;
	else if (tree->c == *key) {
	    if (tree->child != NULL) {
		tree->child = NULL;
		/* free(tree); */
		return 1;
	    }
	}
	else
	    return 0;
	key++;
    }
}
