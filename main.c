/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "StudentList.h"
#include "GradesOperations.h"

/*
This program open "StudentsGrades.txt" file, which contains students ID, first exam grade and late exam grade for each student.
Then making a "Report.txt" file which contains all the statistics.
*/

int
main ()
{
  StudentList *sl = createList ();
  FILE *fp;
  fp = fopen ("StudentsGrades.txt", "r");
  if (fp == NULL){
    printf("Cannot open file!");
    exit(1);
  }
  while (!feof (fp))
    {
      Student *st = (Student *) malloc (sizeof (Student));
      fscanf (fp, "%d %d %d", &st->id, &st->grade1, &st->grade2);
      addToList (sl, st);
    }
    createReportFile(sl);
  fclose (fp);

  return 0;
}
