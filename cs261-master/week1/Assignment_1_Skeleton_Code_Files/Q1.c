/* CS261- Assignment 1 - Q.1*/
/* Name: Alex Cheng
 * Date: 7/11/2018
 * Solution description: This program creates an array of student structs and
 * randomly assigns each student an ID between 0 and 10 using the Fisher-Yates
 * shuffle and gives them scores from 0 to 100. It then sorts them by ID and
 * displays the students along with the max, min, and average scores.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student {
  int id;
  int score;
};

int numStudents = 10;

struct student *allocate() {

  /*Allocate memory for ten students*/
  struct student *myStudents = malloc(numStudents * sizeof(struct student));
  /*Return the pointer*/
  return myStudents;
}

void generate(struct student *students) {

  srand(time(NULL));

  /*Generate random and unique IDs and random scores for ten students,
IDs being between 1 and 10, scores between 0 and 100*/
  // initialize IDs for Fisher Yates and scores
  for (int i = 0; i < numStudents; i++) {
    students[i].id = i + 1;
    int score = rand() % 100 + 1;
    students[i].score = score;
  }
  for (int i = numStudents; i > 0; i--) {
    int j = (rand() % i); // 0-9
    int tmp = students[i - 1].id;
    students[i - 1].id = students[j].id;
    students[j].id = tmp;
  }
}

/* compare function for qsort, source:
https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs
*/
int compare(const void *a, const void *b) {
  const struct student *stud1 = a;
  const struct student *stud2 = b;
  if (stud1->id < stud2->id)
    return -1;
  else if (stud1->id > stud2->id)
    return 1;
  else
    return 0;
}
void output(struct student *students) {

  /*Output information about the ten students in the format:
           ID1 Score1
           ID2 score2
           ID3 score3
           ...
           ID10 score10*/
  qsort(students, numStudents, sizeof(struct student), compare);
  for (int i = 0; i < numStudents; i++) {
    printf("ID:%d Score:%d\n", students[i].id, students[i].score);
  }
}

void summary(struct student *students) {
  /*Compute and print the minimum, maximum and average scores of the
ten students*/
  int max = students[0].score, min = students[0].score;
  double average = 0;
  for (int i = 0; i < numStudents; i++) {
    average += students[i].score;
    if (max < students[i].score)
      max = students[i].score;
    if (min > students[i].score)
      min = students[i].score;
  }
  average = average / numStudents;
  printf("Max: %d\nMin: %d\nAverage: %f\n", max, min, average);
}

void deallocate(struct student *stud) { /*Deallocate memory from stud*/
  free(stud);
}

int main() {

  /*Call allocate*/
  struct student *stud = allocate();
  /*Call generate*/
  generate(stud);
  /*Call output*/
  output(stud);
  /*Call summary*/
  summary(stud);
  /*Call deallocate*/
  deallocate(stud);
  return 0;
}
