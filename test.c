#include <stdio.h>
#include "dbtree.h"

int main(void) {
    /* create our database tree */
    dbtree_create(tree);

    /* store strings */
    dbtree_store(tree, "mano", "v_mano", 0);
    dbtree_store(tree, "man", "v_man", 0);
    dbtree_store(tree, "manovella", "v_manovella", 0);

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

    /* store integers */
    int i  = 1234567;
    long l = 7891011;
    float f = 3.14159;
    double d = 123.45;
    dbtree_store(tree, "integer", &i, sizeof(int));
    dbtree_store(tree, "long", &l, sizeof(long));
    dbtree_store(tree, "float", &f, sizeof(float));
    dbtree_store(tree, "double", &d, sizeof(double));

    /* fetch values */
    printf("\nStoring numbers...\n"
	    "integer   : %d\n"
	    "long      : %ld\n"
	    "float     : %f\n"
	    "double    : %.4e\n",
	    *(int *)dbtree_fetch(tree, "integer"),
	    *(long *)dbtree_fetch(tree, "long"),
	    *(float *)dbtree_fetch(tree, "float"),
	    *(double *)dbtree_fetch(tree, "double"));

    /* remove an entry */
    printf("\nTrying to remove 'mano'... ");
    dbtree_remove(tree, "mano") ? puts("done") : puts("is not defined") ;
    printf("mano      : %s\n", (char *)dbtree_fetch(tree, "mano"));

    /* try to remove a non existent entry */
    printf("\nTrying to remove 'mano'... ");
    dbtree_remove(tree, "mano") ? puts("done") : puts("is not defined") ;
    printf("mano      : %s\n", (char *)dbtree_fetch(tree, "mano"));

    printf("\n");

    /* destroy the database and free all memory */
    dbtree_destroy(tree);

    return 0;
}
