# DBtree, a super-simple C database tree

dbtree is a basic database tree used to store entries associated with their values.
So, here are five simple functions you may use to create your tree and collect keys->values (something similar to a 'map' type):

Note: if you use manually alloced variables (via malloc, calloc..), you have to free them by yourself. However, when freed, their values won't be available for the database anymore. Indeed, the database just stores a pointer to the variable, not its value.

## dbtree_create

The first thing to do is to initialize your database, allocating memory

    dbtree *MyDatabase = malloc(sizeof(dbtree));

    Or simply:
    dbtree_create(MyDatabase);


## dbtree_store

It stores the entry 'key' with the value (pointed by) 'value' of 'size' bytes in the 'tree'.
Set 'size' to 0 if 'value' is a constant, such as "abc" or 1234, so no additional memory will be allocated.

    void *dbtree_store(dbtree *tree, const char *key, void *value);

    Example:
    dbtree_store(MyDatabase, "Name", "John Smith", 0);

Returns a pointer pointing to 'value' if successful, otherwise NULL


## dbtree_fetch

It fetches the value of the entry 'key' stored in 'tree'

    void *dbtree_fetch(dbtree *tree, const char *key);

    Example:
    char *name = (char *) dbtree_fetch(MyDatabase, "Name");

Returns a pointer pointing to the value of 'key' if existent, otherwise NULL


## dbtree_remove

It removes the value of entry 'key' from 'tree'

    int dbtree_remove(dbtree *tree, const char *key);

    Example:
    int exists = dbtree_remove(MyDatabase, "Name");

Returns 1 if successful, otherwise 0


## dbtree_destroy

It cleans the entire database and release (free) memory.

    void dbtree_destroy(dbtree *tree);

    Example:
    dbtree_destroy(MyDatabase);


# TODO

* Overhead reduction: is all that alloc'd memory required?
