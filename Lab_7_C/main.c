
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

    Student *root = NULL;
    int numOfGroup, numOfCourse;
    double averageMark;
    char *firstName = (char*)malloc(20 * sizeof(char));
    char *lastName = (char*)malloc(20 * sizeof(char));
    FILE *fin;
    FILE *fout;
    int i;
    int sw;
    do
    {
        i = 0;
        system("cls");
        printf("\tMenu\n");
        while(i++ < 33) printf("-");
        printf("\n|1.Read from file.\t\t|\n"
               "|2.Add Student.\t\t\t|\n"
               "|3.Print all Students.\t\t|\n"
               "|4.Show student's marks.\t|\n"
               "|5.Show student's info.\t\t|\n"
               "|6.Show students by course.\t|\n"
               "|7.Show students by group.\t|\n"
               "|8.Expel from the university.\t|\n"
               "|9.Expel all students.\t\t|\n"
               "|10.Write To file.\t\t|\n"
               "|11.Exit.\t\t\t|\n");
        i = 0;
        while(i++ < 33) printf("-");
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
            if(root)
            {
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
            getch();
            }
            break;

        case 5:
            if(root)
            {
            system("cls");
            PrintTree(root);
            printf("first name - ");
            scanf("%s", firstName);
            printf("last name - ");
            scanf("%s", lastName);
            printf("average mark - ");
            scanf("%lf", &averageMark);
            system("cls");
            ShowStudentInfo(FindStudent(averageMark, firstName, lastName, root));
            getch();
            }
            break;

        case 6:
            system("cls");
            printf("num of course - ");
            scanf("%d", &numOfCourse);
            PrintCourseRating(root, numOfCourse);
            _getch();
            break;

        case 7:
            system("cls");
            printf("num of group - ");
            scanf("%d", &numOfGroup);
            PrintGroupRating(root, numOfGroup);
            _getch();
            break;

        case 8:
            system("cls");
            PrintTree(root);
            printf("first name - ");
            scanf("%s", firstName);
            printf("last name - ");
            scanf("%s", lastName);
            printf("average mark - ");
            scanf("%lf", &averageMark);
            DeleteStudent(averageMark, firstName, lastName, &root);
            break;

        case 9:					//удаление всех студентов
            system("cls");
            DeleteTree(root);
            root = NULL;
            break;
        case 10:
            fout = fopen("Students.txt", "w");
            WriteToFile(root, fout);
            fclose(fout);
            break;


       }
        printf("Press any button...");
        getch();
    }while(sw != 11);

}
