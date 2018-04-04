/* CS261- HW1 - Program2.c*/
/* Name: Chelsea Starr
 * Date: 4/10/18
 * Solution description: used selection sort
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

void sort(struct student* students, int n){
     int i, j;
     struct student temp;
     /*Sort n students based on their initials*/
     for (i = 2; i < n; i++) {
         for (j = i; j >= 1; j--) {
             if (students[j].initials[0] < students[j - 1].initials[0]) {
                 temp = students[j - 1];
                 students[j - 1] = students[j];
                 students[j] = temp;
             }
         }
     }

     for (i = 2; i < n; i++) {
         for (j = i; j >= 1; j--) {
             if ( students[j].initials[0] == students[j - 1].initials[0] && students[j].initials[1] < students[j - 1].initials[1] ) {
                temp = students[j - 1];
                students[j - 1] = students[j];
                students[j] = temp;
             }
          }
      }
}

int main(){
    int i;
    /*Declare an integer n and assign it a value.*/
    int n = 20;

    srand(time(NULL));

    /*Allocate memory for n students using malloc.*/
    struct student* students = (struct student*) malloc(n * sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/
    for (i = 0; i < n; i++) {
      students[i].initials[0] = (rand() % 26) + 65;
      students[i].initials[1] = (rand() % 26) + 65;
      students[i].score = rand() % 101;
    }

    /*Print the contents of the array of n students.*/
    for (i = 0; i < n; i++) {
      printf("i: %d\tinitial1: %c\tinitial2: %c\tscore: %d\n", i, students[i].initials[0],
      students[i].initials[1], students[i].score);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function*/
    sort(students, n);

    /*Print the contents of the array of n students.*/
    for (i = 0; i < n; i++) {
      printf("i: %d\tinitial1: %c\tinitial2: %c\tscore: %d\n", i, students[i].initials[0],
      students[i].initials[1], students[i].score);
    }

    return 0;
}
