/* CS261- HW1 - Program2.c*/
/* Name: Chelsea Starr
 * Date: 4/10/18
 * Solution description: followed prompts closely
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* ptr;
     ptr = (struct student*) malloc(10 * sizeof(struct student));

     /*return the pointer*/
     return ptr;
}

void generate(struct student* students){
  int i;
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z.
	The scores must be between 0 and 100*/
  for (i = 0; i < 10; i++) {
    students[i].initials[0] = (rand() % (26)) + 65;
    students[i].initials[1] = (rand() % (26)) + 65;
    students[i].score = rand() % 101;

  }


}

void output(struct student* students){
  int i;
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
     for (i = 0; i < 10; i++) {
       printf("Student: %d\n", i);
       printf("first initial: %c\n", students[i].initials[0]);
       printf("second initial: %c\n", students[i].initials[1]);
       printf("score: %d\n\n", students[i].initials[0]);
     }
}

void summary(struct student* students){
     int i;
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int max = -1;
     int min = students[0].score;
     int total = 0;
     int avg;

     for (i = 0; i < 10; i++) {
       total += students[i].score;
       if ( students[i].score < min )
          min = students[i].score;
       if ( students[i].score > max )
          max = students[i].score;
     }
     avg = total/10;

     printf("min: %d\n", min);
     printf("max: %d\n", max);
     printf("avg: %d\n", avg);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     assert(stud != NULL);
     free(stud);
}

int main(){
    struct student* stud = NULL;
    srand(time(NULL));

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
