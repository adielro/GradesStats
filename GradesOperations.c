#include "StudentList.h"
#include <stdlib.h>
#include <stdio.h>

// Method receive a const StudentList and return how many StudentNode there are in the list.
int
howManyStudents (StudentList * const sl)
{
  int count = 0;
  StudentNode *temp = sl->head;
  while (temp != NULL)
    {
      temp = temp->next;
      count++;
    }
  return count;
}

// Function receive a const StudentList and return the amount of students examined only on one exam
int
onlyOneExamNum (StudentList * const sl)
{
  int count = 0;
  StudentNode *temp = sl->head;
  while (temp != NULL)
    {
      if ((temp->st->grade1 == -1 && temp->st->grade2 != -1) || (temp->st->grade2 == -1 && temp->st->grade1 != -1))
	count++;
      temp = temp->next;
    }
  return count;
}

// Function receive a const StudentList and return the amount of students who did not examined at all.
int
noExaminedStudents (StudentList * const sl)
{
  int count = 0;
  StudentNode *temp = sl->head;
  while (temp != NULL)
    {
      if (temp->st->grade1 == -1 && temp->st->grade2 == -1)
	count++;
      temp = temp->next;
    }
  return count;
}

// Function receive a const StudentList and return the percentage of students who failed on the first exam
double
firstExamFailPer (StudentList * const sl)
{
  double failCount = 0;
  double totalExamined = 0;
  StudentNode *temp = sl->head;
  while (temp != NULL)
    {
      if (temp->st->grade1 < 60 && temp->st->grade1 != -1)
	failCount++;
      if (temp->st->grade1 != -1)
	totalExamined++;
      temp = temp->next;
    }
  if (failCount == 0)
    return 0;
  return (failCount / totalExamined) * 100;
}

// Function receive a const StudentList and return the percentage of students who failed on the second exam
double
lateExamFailPer (StudentList * const sl)
{
  double failCount = 0;
  double totalExamined = 0;
  StudentNode *temp = sl->head;
  while (temp != NULL)
    {
      if (temp->st->grade2 < 60 && temp->st->grade2 != -1)
	failCount++;
      if (temp->st->grade2 != -1)
	totalExamined++;
      temp = temp->next;
    }
  if (failCount == 0)
    return 0;
  return (failCount / totalExamined) * 100;
}

// Function receive a const StudentList and return the average on the first exam
double
firstExamAverage (StudentList * const sl)
{
  double totalExamined = 0;
  double sum = 0;
  StudentNode *temp = sl->head;
  while (temp != NULL)
    {
      if (temp->st->grade1 != -1)
	{
	  totalExamined++;
	  sum += temp->st->grade1;
	}
      temp = temp->next;
    }
  return sum / totalExamined;
}

// Function receive a const StudentList and return the average on the second exam
double
lateExamAverage (StudentList * const sl)
{
  double totalExamined = 0;
  double sum = 0;
  StudentNode *temp = sl->head;
  while (temp != NULL)
    {
      if (temp->st->grade2 != -1)
	{
	  totalExamined++;
	  sum += temp->st->grade2;
	}
      temp = temp->next;
    }
  return sum / totalExamined;
}

// Function receive a const StudentList and return the student ID with the highest score.
int highestScoreId(StudentList* const sl){
    int max = -1;
    int id = -1;
    StudentNode* temp = sl -> head;
    while (temp != NULL){
        if (temp -> st -> grade1 > max){
            max = temp -> st -> grade1;
            id = temp -> st -> id;
        }
         if (temp -> st -> grade2 > max){
            max = temp -> st -> grade2;
            id = temp -> st -> id;
        }
        temp = temp -> next;
    }
    return id;
}

// Function receive a const StudentList and return the student ID with the lowest score.
int lowestScoreId(StudentList* const sl){
    int min = 100;
    int id = -1;
    StudentNode* temp = sl -> head;
    while (temp != NULL){
        if (temp -> st -> grade1 < min && temp -> st -> grade1 != -1){
            min = temp -> st -> grade1;
            id = temp -> st -> id;
        }
         if (temp -> st -> grade2 < min && temp -> st -> grade2 != -1){
            min = temp -> st -> grade2;
            id = temp -> st -> id;
        }
        temp = temp -> next;
    }
    return id;
}

// Function receive a const StudentList and create the "Report.txt" file using all the methods above in order to insert the statistics.
void createReportFile(StudentList * const sl){
    FILE* report;
    report = fopen("Report.txt", "w");
    fprintf(report, "Number of students in file: %d\n", howManyStudents(sl));
    fprintf(report, "Number of students examined once: %d\n", onlyOneExamNum(sl));
    fprintf(report, "Number of students that did't examined: %d\n", noExaminedStudents(sl));
    fprintf(report, "First exam failed students percentage: %f\n", firstExamFailPer(sl));
    fprintf(report, "Late exam failed students percentage: %f\n", lateExamFailPer(sl));
    fprintf(report, "First exam average: %f\n", firstExamAverage(sl));
    fprintf(report, "Late exam average: %f\n", lateExamAverage(sl));
    fprintf(report, "Highest score student ID: %d\n", highestScoreId(sl));
    fprintf(report, "Lowest score student ID: %d\n", lowestScoreId(sl));
    fclose(report);
    
}