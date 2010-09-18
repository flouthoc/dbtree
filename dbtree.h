#include <stdio.h>

#ifndef DBTREE_H
    #define DBTREE_H

/* the basic element of an 'dbtree' tree */
struct dbtree {
    char c;
    struct dbtree *sibling;
    void *child;
};

typedef struct dbtree dbtree;

/* store the entry 'key' with the value 'value' in the 'tree' */
void *dbtree_store(dbtree *tree, const char *key, void *value);
/* fetch the value of the entry 'key' stored in 'tree' */
void *dbtree_fetch(dbtree *tree, const char *key);
/* remove the value of entry 'key' from 'tree' */
int  dbtree_remove(dbtree *tree, const char *key);

#endif
