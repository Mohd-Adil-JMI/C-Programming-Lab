#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[10];
int count=0;
void findsubstring(char string[], char substring[])
{
    count=0;
    int m = strlen(string);
    int n = strlen(substring);
    for (int i = 0; i <= m - n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (string[i + j] != substring[j])
            {
                break;
            }
        }
        if (j == n)
        arr[count++]=i;  
    }
}
int main()
{
    char string[100];
    while (1)
    {
        int ch;
        printf("7->Search Substring\n");
        printf("8->To Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        getchar();
        switch (ch)
        {
        case 7:
            printf("Case 7\n\n");
            printf("Enter the string: ");
            gets(string);
            printf("Enter the substring: ");
            char substring[100];
            gets(substring);
            findsubstring(string,substring);
            if (count != 0){
                printf("\"%s\" is a substring of \"%s\" at indeces ",substring,string);
                for (int i = 0; i < count; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }   
            else
                printf("String is not present\n");
            break;
        case 8:
            printf("\nExiting\n");
            exit(0);
        default:
            printf("Wrong Input\n");
        }
    }
    return 0;
}