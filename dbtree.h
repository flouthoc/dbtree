#include <stdio.h>

#ifndef DBTREE_H
    #define DBTREE_H

/* the basic element of an 'dbtree' tree */
typedef struct dbtree {
    char c;
    struct dbtree *previous;
    struct dbtree *next;
    /*struct dbtree *parent;*/
    struct dbtree *child;
    void *value;
} dbtree;

/* store the entry 'key' with the value 'value' in the 'tree' */
void *dbtree_store(dbtree *tree, const char *key, void *value);
/* fetch the value of the entry 'key' stored in 'tree' */
void *dbtree_fetch(dbtree *tree, const char *key);
/* remove the value of entry 'key' from 'tree' */
int  dbtree_remove(dbtree *tree, const char *key);
/* destroy the entire database and release memory */
/*void dbtree_destroy(dbtree *tree);
*/
#endif
