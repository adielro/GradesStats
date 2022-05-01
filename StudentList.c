#include <stdlib.h>
#include <stdio.h>
#include "StudentList.h"

// Method create a new StudentList, initilaize head to be NULL, use malloc and return the new list.
StudentList *
createList ()
{
  StudentList *sl;
  sl = (StudentList *) malloc (sizeof (StudentList));
  sl->head = NULL;
  return sl;
}

// Method delete the StudentList by making the Student NULL, and StudentNode NULL, then freeing the Student and StudentNode and going to the next Node until all nodes are free, then free the StudentList.
void
deleteList (StudentList * sl)
{
  StudentNode *temp;
  while (sl->head != NULL)
    {
      temp = sl->head->next;
      sl->head->st = NULL;
      sl->head = NULL;
      free (sl->head->st);
      free (sl->head);
      sl->head = temp;
    }
  free (sl);
}

// Method receive StudentNode and print it's id and grades.
void
printStudentNode (StudentNode * const sn)
{
  printf ("ID: %d\nGrade 1: %d\nGrade 2: %d\n", sn->st->id, sn->st->grade1,
	  sn->st->grade2);
}

// Method receive a StudentList and print each StudentNode in the last using the printStudentNode function.
void
printStudentList (StudentList * const sl)
{
  StudentNode *temp = sl->head;
  while (temp != NULL)
    {
      printStudentNode (temp);
      temp = temp->next;
    }
}

// Add a new student node from the begining of the list.
void
addToList (StudentList * sl, Student * sn)
{
  StudentNode *newStudNode = (StudentNode *) malloc (sizeof (StudentNode));
  newStudNode->st = sn;
  newStudNode->next = sl->head;
  sl->head = newStudNode;
  return;
}
