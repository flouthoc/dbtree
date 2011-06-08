#include <stdlib.h>
#include "dbtree.h"

void *dbtree_store(dbtree *tree, const char *key, void *value) {
    dbtree *tmp;

    if (tree == NULL)
	return NULL;

    while (*key++ != (char) 0) {
	while (tree->c != *key && tree->next != NULL)
	    tree = tree->next;
	if (tree->c == *key && *key > (char) 0) {
	    if (*(key+1) == (char) 0) {
		if (tree->value != NULL)
		    free(tree->value);
		return tree->value = value;
	    }
	    if (tree->child != NULL)
		tree = tree->child;
	    else {
		key++;
		while (*key++ != (char) 0) {
		    tmp = malloc(sizeof(dbtree));
		    tmp->c = *key;
		    tmp->value = NULL;
		    tree = tree->child = tmp;
		}
		return tree->value = value;
	    }
	} else {
	    tmp = malloc(sizeof(dbtree));
	    tmp->c = *key;
	    tmp->value = NULL;
	    tree = tree->next = tmp;
	    key++;
	    while (*key++ != (char) 0) {
	        tmp = malloc(sizeof(dbtree));
	        tmp->c = *key;
	        tmp->value = NULL;
	        tree = tree->child = tmp;
	    }
	    return tree->value = value;
	}
    }
    return NULL;
}

void *dbtree_fetch(dbtree *tree, const char *key) {
    if (tree == NULL)
	return NULL;

    while (*key++ != (char) 0) {
	while (tree->c != *key && tree->next != NULL)
	    tree = tree->next;
	if (tree->c == *key && *key > (char) 0) {
	    if (*(key+1) == (char) 0) {
		return tree->value;
	    }
	    if (tree->child != NULL)
		tree = tree->child;
	    else
		return NULL;
	} else
	    return NULL;
    }
    return NULL;
}

int dbtree_remove(dbtree *tree, const char *key) {
    if (tree == NULL)
	return 0;

    while (*key++ != (char) 0) {
	while (tree->c != *key && tree->next != NULL)
	    tree = tree->next;
	if (tree->c == *key && *key > (char) 0) {
	    if (*(key+1) == (char) 0) {
		if (tree->value != NULL)
		    tree->value = NULL;//free(tree->value);
		else
		    return 0;
		if (tree->child == NULL) {
		    if (tree->previous != NULL) {
			tree->previous->next = tree->next;
			free(tree);
		    }
		}
		return 1;
	    }
	    if (tree->child != NULL)
		tree = tree->child;
	    else
		return 0;
	} else
	    return 0;
    }
    return 0;
}
