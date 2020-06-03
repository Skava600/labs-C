#include "Students.h"


//*********ДОБАВИТЬ СТУДЕНТА***********************************************************
void AddStudent(Student **root)
{
    system("cls");
    int numOfTerms = 0;
    Student* st = (Student*)malloc(sizeof(Student));
    st->firstName = (char*)malloc(20 * sizeof(char));
    st->lastName = (char*)malloc(20 * sizeof(char));
    st->rank = 0;
    st->prevRank = 0;
    st->totalAverageMark = 0;
    printf("First name - ");
    scanf("%s", st->firstName);
    printf("Last name of %s- ", st->firstName);
    scanf("%s", st->lastName);
    do
    {
        printf("Course of %s %s- ", st->firstName, st->lastName);
        scanf("%d", &st->course);
    }while(st->course < 1 || st->course > 4);
    printf("Group of %s %s - ", st->firstName, st->lastName);
    scanf("%d", &st->group);

    for (numOfTerms = 0; numOfTerms < st->course * 2; numOfTerms++)
    {
        st->termMarks[numOfTerms].averageMark = 0;
    }

    for (numOfTerms = 0; numOfTerms < st->course * 2; numOfTerms++)
    {
        printf("%d term's marks of %s %s: ", numOfTerms + 1, st->firstName, st->lastName);

        for (int i = 0; i < MAX_OF_MARKS; i++)
        {
            do
            {
                scanf("%d", &st->termMarks[numOfTerms].marks[i]);
            }while(st->termMarks[numOfTerms].marks[i] < 0 || st->termMarks[numOfTerms].marks[i] > 10);
            st->termMarks[numOfTerms].averageMark += st->termMarks[numOfTerms].marks[i];
        }
        st->termMarks[numOfTerms].averageMark /= MAX_OF_MARKS;
        st->totalAverageMark += st->termMarks[numOfTerms].averageMark;
    }
    st->totalAverageMark /= numOfTerms;
    st->currentAverageMark = st->termMarks[numOfTerms - 1].averageMark;
    st->rise = st->termMarks[numOfTerms - 1].averageMark - st->termMarks[numOfTerms - 2].averageMark;

    AddNode(root, st);

    SetRanks(root, 'a', 0);
}
//*********ДОБАВЛЕНИЕ СТУДЕНТА В ДЕРЕВО*****************************************
void AddNode(Student **root, Student *student)
{
    if (!(*root))
    {
        *root = (Student*)calloc(1, sizeof(Student));
        (*root) = student;
        (*root)->left = (*root)->right = NULL;
    }
    else
    {
        if ((*root)->currentAverageMark > student->currentAverageMark)
        {
            AddNode(&(*root)->left, student);
        }
        else
        {
            AddNode(&(*root)->right, student);
        }
    }
}
//******************************************************************

//***************ЧТЕНИЕ ИЗ ФАЙЛА СТУДЕНТОВ**************************
void ReadFromFile(Student **root, FILE *fp)
{
    while (!feof(fp))
    {
        int numOfTerms = 0;
        Student *st = (Student*)malloc(sizeof(Student));

        st->firstName = (char*)malloc(20 * sizeof(char));
        st->lastName = (char*)malloc(20 * sizeof(char));
        st->rank = 0;
        st->prevRank = 0;
        st->totalAverageMark = 0;

        if (fscanf(fp, "%s", st->firstName) == EOF)
        {
            SetRanks(root, 'a', 0);
            return;
        }
        fscanf(fp, "%s", st->lastName);
        fscanf(fp, "%d", &st->course);
        fscanf(fp, "%d", &st->group);

        for (numOfTerms = 0; numOfTerms < st->course * 2; numOfTerms++)
        {
            st->termMarks[numOfTerms].averageMark = 0;
        }

        for (numOfTerms = 0; numOfTerms < st->course * 2; numOfTerms++)
        {
            for (int i = 0; i < MAX_OF_MARKS; i++)
            {
                fscanf(fp, "%d", &st->termMarks[numOfTerms].marks[i]);
                st->termMarks[numOfTerms].averageMark += st->termMarks[numOfTerms].marks[i];
            }
            st->termMarks[numOfTerms].averageMark /= MAX_OF_MARKS;
            st->totalAverageMark += st->termMarks[numOfTerms].averageMark;
        }
        st->totalAverageMark /= numOfTerms;
        st->currentAverageMark = st->termMarks[numOfTerms - 1].averageMark;
        st->rise = st->termMarks[numOfTerms - 1].averageMark - st->termMarks[numOfTerms - 2].averageMark;

        fgetc(fp);
        AddNode(root, st);
    }

    SetRanks(root, 'a', 0);
}
//******************************************************************

//********ЗАПИСЬ В ФАЙЛ*********************************************
void WriteToFile(Student *root, FILE *fp)
{
    if (root)
    {
        WriteToFile(root->right, fp);

        fprintf(fp, "%s %s %d %d %f %f", root->firstName, root->lastName, root->course, root->group, root->currentAverageMark, root->rise);

        for (int numOfTerms = 0; numOfTerms < root->course * 2; numOfTerms++)
        {
            for (int i = 0; i < MAX_OF_MARKS; i++)
            {
                fprintf(fp, " %d", root->termMarks[numOfTerms].marks[i]);
            }
        }
        fprintf(fp, "\n");

        WriteToFile(root->left, fp);
    }
}
//**********************************************************


//***********УДАЛЕНИЕ СТУДЕНТА******************************
void DeleteStudent(double currentAverageMark, char *firstName, char *lastName, Student **root)
{
    Student *current = *root;
    Student *parent = NULL;
    Student *deletingStudent;

    while (current)
    {
        if (!strcmp(current->firstName, firstName)
            && !strcmp(current->lastName, lastName)
            && current->currentAverageMark == currentAverageMark)
        {
            break;
        }
        else
        {
            parent = current;

            if (currentAverageMark < current->currentAverageMark)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
    if (!current) return;

    if (!current->right)
    {
        if (!parent)
        {
            deletingStudent = *root;
            *root = current->left;
        }
        else
        {
            if (current == parent->left)
            {
                deletingStudent = parent->left;
                parent->left = current->left;
            }
            else
            {
                deletingStudent = parent->right;
                parent->right = current->left;
            }
        }
    }
    else
    {
        Student *leftMost = current->right;
        parent = NULL;

        while (leftMost->left)
        {
            parent = leftMost;
            leftMost = leftMost->left;
        }
        if (parent)
        {
            deletingStudent = parent->left;
            parent->left = leftMost->right;
        }
        else
        {
            deletingStudent = current->right;
            current->right = leftMost->right;
        }
        current->course = leftMost->course;
        current->currentAverageMark = leftMost->currentAverageMark;
        current->totalAverageMark = leftMost->totalAverageMark;
        current->firstName = leftMost->firstName;
        current->group = leftMost->group;
        current->lastName = leftMost->lastName;
        current->prevRank = leftMost->prevRank;
        current->rank = leftMost->rank;
        current->rise = leftMost->rise;

        for (int numOfTerms = 0; numOfTerms < current->course * 2; numOfTerms++)
        {
            for (int i = 0; i < MAX_OF_MARKS; i++)
            {
                current->termMarks[numOfTerms].marks[i] = leftMost->termMarks[numOfTerms].marks[i];
            }
            current->termMarks[numOfTerms].averageMark = leftMost->termMarks[numOfTerms].averageMark;
        }
        current->currentAverageMark = leftMost->currentAverageMark;
    }
    SetRanks(root, 'a', 0);

    free(deletingStudent);
}

//***********ПОИСК СТУДЕНТА ПО ИМЕНИ ФАМИЛИИ И СРЕДНЕЙ ОЦЕНКЕ***********************
Student* FindStudent(double averageMark, char *firstName, char *lastName, Student *root)
{
    if (root)
    {
        if (!strcmp(root->firstName, firstName) && !strcmp(root->lastName, lastName))
        {
            return root;
        }
        else if (averageMark > root->currentAverageMark)
        {
            FindStudent(averageMark, firstName, lastName, root->right);
        }
        else if(averageMark < root->currentAverageMark)
        {
            FindStudent(averageMark, firstName, lastName, root->left);
        }
        else return NULL;
    }
    return NULL;
}
//****************************************************************************

//******************ВЫВЕСТИ ОЦЕНКИ СТУДЕНТА***********************************
void ShowStudentMarks(Student *st)
{
    if (!st)
    {
        puts("No matches");
        return;
    }
    printf("%s's marks\n", st->firstName);

    for (int numOfTerms = 0; numOfTerms < st->course * 2; numOfTerms++)
    {
        printf("%d term's marks: ", numOfTerms + 1);

        for (int i = 0; i < MAX_OF_MARKS; i++)
        {
            printf("%d ", st->termMarks[numOfTerms].marks[i]);
        }
        puts("");
    }
}
//*******************************************************************************

//***********ПОЛНАЯ  ИНФОРМАЦИЯ О СТУДЕНТЕ*****************************************
void ShowStudentInfo(Student* st)
{
    if (!st)
    {
        puts("No matches");
        return;
    }

    printf("Name - %s", st->firstName);
    printf("\nSurname - %s", st->lastName);
    printf("\nCourse - %d", st->course);
    printf("\nGroup - %d", st->group);
    printf("\nTotal average mark - %.2f", st->totalAverageMark);
    printf("\nCurrent average mark - %.2f", st->currentAverageMark);

    for (int numOfTerm = 0; numOfTerm < st->course * 2; numOfTerm++)
    {
        printf("\n%d term's marks: ", numOfTerm + 1);

        for (int i = 0; i < MAX_OF_MARKS; i++)
        {
            printf("%d ", st->termMarks[numOfTerm].marks[i]);
        }
    }
}
//*************************************************************

//***********РАЗМЕР ДЕРЕВА*************************************
int GetSize(Student *root)
{
    if (root)
    {
        return 1 + GetSize(root->left) + GetSize(root->right);
    }
    return 0;
}
//****************************************************************

//***********ВЫВЕСТИ ДЕРЕВО**************************************
void PrintTree(Student *root)
{
    if (root)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        PrintTree(root->right);

        printf("# %d", root->rank);

        if (root->prevRank - root->rank > 0)
        {
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
        }
        else if (root->prevRank - root->rank < 0)
        {
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
        }
        if (root->prevRank - root->rank != 0 && root->prevRank != 0)
            printf("(%+d)", root->prevRank - root->rank);

        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
        printf(". %s %s, course %d group %d, average mark - %.2f", root->firstName, root->lastName, root->course, root->group, root->currentAverageMark);

        if (root->rise > 0)
        {
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
        }
        else if (root->rise < 0)
        {
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
        }

        if (root->rise == 0.)
        {
            puts("");
        }
        else
        {
            printf("(%+.2f)\n", root->rise);
        }
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

        PrintTree(root->left);
    }
}
//***************************************************************

//************ВЫВЕСТИ РЕЙТИНГ ПО ГРУППЕ**************************
void PrintGroupRating(Student* root, int group)
{
    if (root)
    {
        PrintGroupRating(root->right, group);
        if (root->group == group)
        {
            printf("%d. %s %s, course %d group %d, average mark - %.2f\n", root->rank, root->firstName, root->lastName, root->course, root->group, root->currentAverageMark);
        }
        PrintGroupRating(root->left, group);
    }
}
//******************************************************************

//**********ВЫВЕСТИ РЕЙТИНГ ПО КУРСУ********************************
void PrintCourseRating(Student *root, int course)
{
    if (root)
    {
        PrintCourseRating(root->right, course);
        if (root->course == course)
        {
            printf("%d. %s %s, course %d group %d, average mark - %.2f\n", root->rank, root->firstName, root->lastName, root->course, root->group, root->currentAverageMark);
        }
        PrintCourseRating(root->left, course);
    }
}
//*************УДАЛИТЬ ДЕРЕВА******************************
void DeleteTree(Student *root)
{
    if (root)
    {
        DeleteTree(root->left);
        DeleteTree(root->right);
        free(root->firstName);
        free(root->lastName);
        free(root);
    }
}

//**************БАЛАНСИРОВКА ДЕРЕВА****************************
void BalanceTree(Student **root)
{
    MakeVine(root);
    BalanceVine(root);
}
//***************************************************************

//********НАЗНАЧИТЬ МЕСТО В РЕЙТИНГЕ*****************************
void SetRanks(Student **root, char field, int fieldValue)
{
    MakeVine(root);

    int rank = 1;
    Student *current = *root;

    while (current)
    {
        switch (field)
        {
        case 'g':
            if (current->group == fieldValue)
            {
                current->prevRank = current->rank;
                current->rank = rank++;
            }
            break;
        case 'c':
            if (current->course == fieldValue)
            {
                current->prevRank = current->rank;
                current->rank = rank++;
            }
            break;
        default:
            current->prevRank = current->rank;
            current->rank = rank++;
            break;
        }
        current = current->left;
    }
    BalanceVine(root);
}
//*********************************************************

//**********ОПРЕДЕЛЕНИЕ ЛОЗЫ*******************************
void MakeVine(Student **root)
{
    Student *current = *root;
    Student *parrent = NULL;

    while (current)
    {
        if (!current->right)
        {
            parrent = current;
            current = current->left;
        }
        else
        {
            RotateLeft(&parrent, &current, root);
        }
    }
}
//**********************************************************

//*****************БАЛАНСИРОВКА ЛОЗЫ*********************
void BalanceVine(Student **root)
{
    Student *black = NULL;
    Student *red = *root;

    for (int n = 1; n < log(GetSize(*root)) / log(2) - 0.5; n++)
    {
        for (int i = 0; i < GetSize(*root) / pow(2, n) - 1; i++)
        {
            RotateRight(&black, &red, root);
            black = red;
            red = red->left;
        }
        black = NULL;
        red = *root;
    }
}

//левый поворот для составления лозы
void RotateLeft(Student **parrent, Student **current, Student **root)
{
    Student* subR = (*current)->right;
    Student* subRL = subR->left;

    (*current)->right = subRL;
    subR->left = *current;
    if (*parrent) {
        (*parrent)->left = subR;
    }
    else {
        *root = subR;
    }
    *current = subR;
}

//Правый поворот для балансировки лозы
void RotateRight(Student **parrent, Student **current, Student **root)
{
    Student* subL = (*current)->left;
    Student* subLR = subL->right;

    (*current)->left = subLR;
    subL->right = *current;
    if (*parrent) {
        (*parrent)->left = subL;
    }
    else {
        *root = subL;
    }
    *current = subL;
}

