#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DBTREE_H
    #define DBTREE_H

/* the basic element of an 'dbtree' tree */
typedef struct dbtree {
    char c;
    struct dbtree *previous;
    struct dbtree *next;
    struct dbtree *parent;
    struct dbtree *child;
    void *value;
    unsigned int size;
} dbtree;

/* create a new database allocating memory for node 'name' */
#define dbtree_create(name) dbtree *name = malloc(sizeof(dbtree));
/* store the entry 'key' with the value 'value' of 'size' bytes in the 'tree' */
void *dbtree_store(dbtree *tree, const char *key, void *value, unsigned int size);
/* fetch the value of the entry 'key' stored in 'tree' */
void *dbtree_fetch(dbtree *tree, const char *key);
/* remove the value of entry 'key' from 'tree' */
int  dbtree_remove(dbtree *tree, const char *key);
/* destroy the entire database and release memory */
void dbtree_destroy(dbtree *tree);

#endif
