#include "dbtree.h"

inline static void *__child_push(dbtree *tree, const char *key, void *value, unsigned int size) {
    key++;
    while (*key != (char) 0) {
	dbtree* tmp = malloc(sizeof(dbtree));
	tmp->c = *key;
	key++;
	tmp->value = NULL;
	tmp->child = NULL;
	tmp->previous = NULL;
	tmp->next = NULL;
	tmp->parent = tree;
	tree = tree->child = tmp;
    }

    tree->size = size;
    if (size > 0) {
	tree->value = malloc(size);
	memcpy(tree->value, value, size);
    }
    else {
	tree->value = value;
    }

    return tree->value;
}

void *dbtree_store(dbtree *tree, const char *key, void *value, unsigned int size) {
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
	    else
		return __child_push(tree, key, value, size);
	} else {
	    tmp = malloc(sizeof(dbtree));
	    tmp->c = *key;
	    tmp->value = NULL;
	    tmp->child = NULL;
	    tmp->next = NULL;
	    tmp->parent = NULL;
	    tmp->previous = tree;
	    tree = tree->next = tmp;
	    return __child_push(tree, key, value, size);
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
		if (tree->value != NULL) {
		    if (tree->size > 0)
			free(tree->value);
		    tree->value = NULL;
		}
		else
		    return 0;
		if (tree->child == NULL) {
		    if (tree->previous != NULL) {
			tree->previous->next = tree->next;
			if (tree->next != NULL)
			    tree->next->previous = tree->previous;
			if (tree->parent != NULL)
			    tree->parent->child = NULL;
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

void dbtree_destroy(dbtree *tree) {
    if (tree->next)
	dbtree_destroy(tree->next);
    if (tree->child)
	dbtree_destroy(tree->child);
    while (tree) {
	dbtree *next = tree->next;
	if (tree->size > 0 && tree->value != NULL)
	    free(tree->value);
	free(tree);
	tree = next;
    }
}
