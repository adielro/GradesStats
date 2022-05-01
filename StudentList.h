#ifndef STUDENTLIST_H
#define STUDENT_LIST_H
/*
StudentList head, stamps and structs.
*/

typedef struct
{
  int id;
  int grade1, grade2;
} Student;

typedef struct studentNode
{
  Student *st;
  struct studentNode *next;
} StudentNode;

typedef struct
{
  StudentNode *head;
} StudentList;

// list functions
StudentList *createList ();
void deleteList (StudentList *);
void printStudentNode (StudentNode * const);
void printStudentList (StudentList * const);
void addToList (StudentList *, Student *);
#endif
