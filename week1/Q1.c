/* CS261- Assignment 1 - Q.1*/
/* Name: Cory Kertz
 * Date:
 * Solution description:
 */

 // Runs with:
 // gcc -Wall -std=c99 -o bin/Q1 Q1.c
 // ./bin/Q1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

static int SIZE = 10;

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* students = malloc(SIZE * sizeof(struct student));
     /*Return the pointer*/
    return students;
}

void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students,
IDs being between 1 and 10, scores between 0 and 100*/
    srand (time(NULL));
    int id, score, j;
    int position = 0;
    int tries = 0;
    _Bool exists;
    while (position < SIZE){
        id = (rand() % 10) + 1;

        tries++;
        //printf("id:  %d \n", id);

        exists = 0;
        j = 0;
        while(!exists && j < position)
        {
            if(students[j].id == id){
                exists = 1;
            }else{
                j++;
            }
        }
        // If the id value did not exist in the struct add it to the struct with its score
        if(!exists){
            score = (rand() % 101);
            students[position].id = id;
            students[position].score = score;
            //printf("student.id:  %d \n", students[position].id);
            //printf("student.score: %d \n", students[position].score);
            position++;
           // printf("tries: %d \n", tries);
        }
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for (int i = 0; i < SIZE; i++)
    {
        printf("ID%d Score%d \n", students[i].id, students[i].score);
    }


}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the
ten students*/
    int total = 0,
    min = students[0].score,
    max = students[0].score;
    for (int i = 1; i < SIZE; i++)
    {
        if (min > students[i].score){
            min = students[i].score;
        }
        if (max < students[i].score){
            max = students[i].score;
        }
        total += students[i].score;
    }

    printf("Minimum: %d\nMaximum: %d\nAverage: %d\n", min, max, (total/SIZE));

}

void deallocate(struct student* stud){
    if (!(stud == NULL)){
      /*Deallocate memory from stud*/
     free(stud);
    }

}

int main(){
    struct student* stud = NULL;

    /*Call allocate*/
    stud = allocate();

    /*Call generate*/
    generate(stud);

    /*Call output*/
    output(stud);

    /*Call summary*/
    summary(stud);

    /*Call deallocate*/
    deallocate(stud);

    output(stud);

    return 0;
}
