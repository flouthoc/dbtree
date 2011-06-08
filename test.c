#include <stdio.h>
#include <stdlib.h>
#include "dbtree.h"

int main(void) {
    /* create our database tree */
    dbtree *tree = malloc(sizeof(dbtree));

    /* store strings */
    dbtree_store(tree, "mano", "v_mano");
    dbtree_store(tree, "man", "v_man");
    dbtree_store(tree, "manovella", "v_manovella");

    /* fetch values of our entries */
    printf("\nStoring strings...\n"
	"mano      : %s\n"
	"man       : %s\n"
	"manovella : %s\n"
	"undefined : %s\n",
	(char *)dbtree_fetch(tree, "mano"),
	(char *)dbtree_fetch(tree, "man"),
	(char *)dbtree_fetch(tree, "manovella"),
	(char *)dbtree_fetch(tree, "undefined"));

    /* remove an entry */
    printf("\nTrying to remove 'mano'... ");
    dbtree_remove(tree, "mano") ? puts("done") : puts("is not defined") ;
    printf("mano      : %s\n", (char *)dbtree_fetch(tree, "mano"));

    /* try to remove a non existent entry */
    printf("\nTrying to remove 'mano'... ");
    dbtree_remove(tree, "mano") ? puts("done") : puts("is not defined") ;
    printf("mano      : %s\n", (char *)dbtree_fetch(tree, "mano"));

    /* store integers or... whatever. TODO: dbtree_remove() won't work on dynamic variables */
/*
    int i = 8394;
    dbtree_store(tree, "man", &i);
    int *p = dbtree_fetch(tree, "man");
    printf("\nStoring integers...\nman       : %d\n", *p);
*/

    /* remove string. TODO: dbtree_destroy() needed */
    dbtree_remove(tree, "man");
    dbtree_remove(tree, "manovella");

    return 0;
}
