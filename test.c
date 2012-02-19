#include <stdio.h>
#include "dbtree.h"

int main(void) {
    /* create our database tree */
    dbtree_create(tree);

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

    printf("\n");

    dbtree_destroy(tree);

    return 0;
}
