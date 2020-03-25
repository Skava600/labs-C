#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
void show (int *a, int n);
void zerkgl (int *a, int n);
void zerkpb (int *a, int n);
int main()
{
    int *a;  // указатель на массив
    int  n, ki=0, max;
    printf("Enter n: ");
    scanf("%d", &n);
    a = (int*)malloc( (unsigned long long int)(n * (n - 1) )  * sizeof(int));
    srand((10));
    for (int i = 0; i < n - 1; i++)
      {
        printf("|");
        for (int j = 0; j < n; j++)
        {
          *(a + i * n + j) = rand()%200 + 1;
          printf ("\t%d",*(a + i * n + j));
        }
        printf ("\t|\n");
      }
    max = a[0];
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(max<*(a + i * n +j))
            {
                max = *(a + i * n + j);
                ki= i;
            }
        }
    }
    int temp;
     printf("\n%d %d\n", max, ki);
    for(int i = 0; i < n; i++)
    {
        *(a + (n - 1) * n + i) = 0;// добавление строки нулей в нную строку
    }
    // ** свап по строкам элементов=--------------------------------
    for(int i = n - 1; i > ki + 1; i--)
    {
        for(int j = 0; j < n; j++)
        {
            temp = *(a + i * n +j);
            *(a + i * n +j) = *(a + (i-1)*n + j);
            *(a + (i-1)*n + j) = temp;
        }
    }
    // --------------------------------
    show (a,n);
    zerkgl (a,n);
    zerkpb (a,n);
    return 0;
}
// ** Показать массив -----------------------------------------
void show (int *a, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
        {
          printf ("\t%d",*(a + i * n + j));
        }
        printf ("\t|\n");
    }
}
// ** Зеокально относительно главной ----------------------------------
void zerkgl(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
            {
            int tmp = *(a + i * n + j);
            *(a + i * n + j) = *(a + j * n + i);
            *(a + j * n + i) = tmp;
            }
    }
    show(a,n);

}

// ** зеркально относительно поб диагонали -------------------------
void zerkpb(int *a, int n)
{
    for(int i = 0; i < n - 1;i++)
          for(int j = 0; j < n - i; j++)
          {
             int tmp = *(a + i * n + j);
              *(a + i * n + j) = *(a + (n - j - 1) * n + n-i-1);
             *(a + (n - j - 1) * n + n-i-1) = tmp;
          }
    show(a,n);
}
//-----------------------------------------------------------
