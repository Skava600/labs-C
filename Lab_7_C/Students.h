#ifndef STUDENTS_H
#define STUDENTS_H
#define MAX_OF_MARKS 5
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

typedef struct TermMarks
{
    int marks[MAX_OF_MARKS];
    double averageMark;
} TermMarks;

typedef struct Student
{
    char *firstName;
    char *surName;
    struct TermMarks termMarks[8];
    double currentAverageMark;
    double totalAverageMark;
    double rise;
    int group;
    int course;
    int rank;
    int prevRank;
    unsigned char height;
    struct Student *left;
    struct Student *right;
    struct Student *parent;
} Student;

/*treatment of students*/
void AddStudent(Student **root);
void SetRanks(Student **root, char field, int fieldValue);
void ReadFromFile(Student **root, FILE *fp);
void WriteToFile(Student *root, FILE *fp);
void DeleteStudent(double averageMark, char *firstName, char *lastName, Student **root);
Student* FindStudent(double averageMark, char *firstName, char *lastName, Student *root);
void ShowStudentMarks(Student *st);
void ShowStudentInfo(Student *st);
void PrintGroupRating(Student *root, int group);
void PrintCourseRating(Student *root, int course);

/*treatment with tree*/
int GetSize(Student *root);
void AddNode(Student **root, Student *student);
void PrintTree(Student *root);
void DeleteTree(Student *root);
void BalanceTree(Student **root);
void MakeVine(Student **root);
void BalanceVine(Student **root);
void RotateLeft(Student **parrent, Student **current, Student **root);
void RotateRight(Student **parrent, Student **current, Student **root);
#endif /* STUDENTS_H*/
