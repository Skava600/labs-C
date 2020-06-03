
#include <stdio.h>
#include "Students.h"

/*
    Вариант 16
    Рейтинг студентов. Программа рассчитывает рейтинг студентов
специальности «Информатика». Рейтинг учитывает все оценки,
полученные студентами во время сессий – как положительныfе, так
и отрицательные. Можно просмотреть рейтинг по курсам, по
группам. Отображается текущий средний балл, рост
(положительный или отрицательный) относительно последней
сессии, изменение места в рейтинге.
*/

int main()
{
    //ЕЩЕ НЕ ЗАКОНЧИЛ ЛАБОРАТОРНУЮ
    Student *root = NULL;
    int numOfGroup, numOfCourse;
    double averageMark;
    char *firstName = (char*)malloc(20 * sizeof(char));
    char *lastName = (char*)malloc(20 * sizeof(char));
    char field;
    FILE *fin;
    FILE *fout;
    int i = 0;
    int sw;
    do
    {
        i = 0;
        system("cls");
        printf("\tMenu\n");
        while(i++ < 25) printf("-");
        printf("\n|1.Read from file.\t|\n|2.Add Student.\t\t|\n|3.Print all Students.\t|\n|4.Show student's marks.|\n"
               "|5.Show student's info. |\n|6.Show students by course.|\n|7.Show students by group.|\n|7.Write To file.\t|\n");
        i = 0;
        while(i++ < 25) printf("-");
        printf("\nEnter action: ");
        scanf("%d", &sw);
        switch(sw)
        {

        case 1:
            fin = fopen("Students.txt", "r");
            ReadFromFile(&root, fin);
            break;

        case 2: AddStudent(&root);break;
        case 3: PrintTree(root);break;
        case 4:
            system("cls");
                            PrintTree(root);
                            printf("first name - ");
                            scanf("%s", firstName);
                            printf("last name - ");
                            scanf("%s", lastName);
                            printf("average mark - ");
                            scanf("%lf", &averageMark);

                            system("cls");
                            ShowStudentMarks(FindStudent(averageMark, firstName, lastName, root));
                            _getch();
                            break;
       }
    }while(sw != 8);

}
