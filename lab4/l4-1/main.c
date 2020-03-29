#include <stdio.h>

int main()
{
    char str[100];
    printf("Enter text: ");
    gets(str);
    for(int i = 0; str[i] != NULL; i++)
    {
        printf("%c",str[i]);
        if( (str[i] == ',' || str[i] == ':' || str[i] == '.' || str[i] == ';' )  && (str[i+1] != ' ') )
        {
            printf(" ");
        }
    }
    return 0;
}
