/* CS261- HW1 - Program2.c*/
/* Name: Chelsea Starr
 * Date: 4/10/18
 * Solution description: used selection sort
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
    int i, j;
     /*Sort the array of integeres of length n*/
    for (i = 2; i < n; i++)
    {
        for (j = i; j >= 1; j--)
        {
            if (number[j] < number[j - 1])
            {
                int temp = number[j - 1];
                number[j - 1] = number[j];
                number[j] = temp;
            }
        }
    }

}

int main(){
    int i, n;
    srand(time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
    n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int* ptr = (int*) malloc(n * sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    for (i = 0; i < n; i++ ) {
      ptr[i] = rand() % 101;
    }

    /*Print the contents of the array.*/
    printf("BEFORE SORT:\n");
    for (i = 0; i < n; i++ ) {
      printf("i: %d\t%d\n", i, ptr[i]);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/
    sort(ptr, n);

    /*Print the contents of the array.*/
    printf("AFTER SORT:\n");
    for (i = 0; i < n; i++ ) {
      printf("i: %d\t%d\n", i, ptr[i]);
    }

    return 0;
}
