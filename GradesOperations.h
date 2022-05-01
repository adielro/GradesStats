#ifndef GRADES_OPERATIONS_H
#define GRADES_OPERATIONS_H
void createReportFile (StudentList * const);
int howManyStudents (StudentList * const);
int onlyOneExamNum (StudentList * const);
int noExaminedStudents (StudentList * const);
double firstExamFailPer (StudentList * const);
double lateExamFailPer (StudentList * const);
double firstExamAverage (StudentList * const);
double lateExamAverage (StudentList * const);
int highestScoreId (StudentList * const);
int lowestScoreId (StudentList * const);
#endif
