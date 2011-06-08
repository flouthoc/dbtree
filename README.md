# DBtree, a super-simple C database tree

dbtree is a basic database tree used to store entries associated with their values.
So, here are three simple functions you may use to create your tree and collect keys->values (something similar to a 'map' type):

First initialize your dbtree

    dbtree *mytree = malloc(sizeof(dbtree));


## dbtree_store

It stores the entry 'key' with the value (pointed by) 'value' in the 'tree'

    void *dbtree_store(dbtree *tree, const char *key, void *value);

Returns a pointer pointing to 'value'


## dbtree_fetch

It fetches the value of the entry 'key' stored in 'tree'

    void *dbtree_fetch(dbtree *tree, const char *key);

Returns a pointer pointing to the value of 'key' if existent, otherwise NULL


## dbtree_remove

It removes the value of entry 'key' from 'tree'

    int  dbtree_remove(dbtree *tree, const char *key);

Returns 1 if successful, otherwise 0


## dbtree_destroy

To be implemented; it will let you destroy the entire database and release (free) memory.
