#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n = 0;
    int *a, m = 0, l = 0;
    short int flag = 1;
    while(flag)
    {
    printf("\nEnter n=");
    scanf("%u",&n);
    if( n > 0) flag = 0;
    }
    a = (int*)malloc( (unsigned long long int)n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    while(!flag)
    {
        printf("Enter m and l:");
        scanf("%i %i",&m, &l);
        if (m < (int)n && m>=0 && l > 0) flag = 1;
    }
    for(int mid,  left = 0,  right = (int)n - 1, i = 1; left <= right; i++)
    {
        mid = (left + right) / 2;

        if ( m == mid) // есди центральный элемент равен искомому
        {
            flag = 1;
            break;
        }
        if ( i == l) // если счетчик доходит до количества допустимых шагов
        {
            flag = 0;
            break;
        }
        if (a[m] < a[mid]) // если элемент слева от мида
        {
            right = mid - 1;

        }
        if (a[m] > a[mid]) // есди искомый элемент справа о мида
            left = mid + 1;
    }
    if (flag == 1)
        printf("Searching is possible");
    else
        printf("Impossible");
    free(a);
    return 0;
}
