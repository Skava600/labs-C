#include <stdio.h>

int main()
{
    char str[100];

    int flag = 1;
    int prov = 0;
    int val1 = 0,val2 = 1;
    while(flag == 1 || val1 != val2 || prov != 1)
    {
        prov = 0;
        val1 = 0;
        val2 = 0;
        printf("Enter brackets");
        flag  = 0;
        gets(str);
        for(int i = 0; str[i] != NULL; i++)
            if(str[i] != '(' && str[i] != ')') 
            {
                flag = 1;
                break;
            }
        for(int i = 0; str[i] != NULL; i++)
        {
            if(str[i] == '(') val1++;
            if(str[i] == ')') val2++;
            if(str[i] == '(' && str[i+1] == ')' ) prov++;
        }
    }
    str[1] = '[';
    int i;
    for( i = 2; str[i]! = ')'; i++)
    {
      str[i] = '{';
    }
    for(; str[i+2] != NULL; i++)
    {
        str[i] = '}';
    }
    str[i] = ']';
    puts(str);
    return 0;
}
