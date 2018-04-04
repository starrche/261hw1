/* CS261- HW1 - Program1.c*/
/* Name: Chelsea Starr
 * Date: 4/10/18
 * Solution description: followed prompts closely
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /* Increment a */
    (*a)++;

    /* Decrement  b */
    (*b)--;

    /* Assign a-b to c */
    c = *a - *b;

    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x, y, z, a;
    srand(time(NULL));
    x = rand()%11;
    y = rand()%11;
    z = rand()%11;

    /* Print the values of x, y and z */
    printf("x=%d ", x);
    printf("y=%d ", y);
    printf("z=%d\n", z);

    /* Call foo() appropriately, passing x,y,z as parameters */
    a = foo(&x, &y, z);

    /* Print the values of x, y and z */
    printf("x=%d ", x);
    printf("y=%d ", y);
    printf("z=%d\n", z);

    /* Print the value returned by foo */
    printf("a=%d\n", a);


    /* Is the return value different than the value of z?  Why?
     * Yes, they are different because z is not passed in as reference or pointer into foo.
     * The value held in z is not being adjusted, it is just being copied into int c in the foo function.x
     */

    return 0;
}
