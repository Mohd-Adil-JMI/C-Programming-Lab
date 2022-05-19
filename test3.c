#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findsubstring(char string[], char substring[])
{
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
            return i;
    }
    return -1;
}
void replaceSubstring(char string[], char sub[], char new_str[])
{
    int index = findsubstring(string, sub);
    char s1[100] = {'\0'}, s2[100] = {'\0'};
    int n = strlen(sub);
    for (int i = 0; i < index; i++)
    {
        s1[i] = string[i];
    }
    int j = 0;
    for (int i = index + n; string[i] != '\0'; i++)
    {
        s2[j++] = string[i];
    }
    sprintf(string, "%s%s%s", s1, new_str, s2);
}
int main()
{
    char string[100], sub[100], new_str[100];
    printf("\nEnter a string: ");
    gets(string);
    while (1)
    {
        int ch;
        printf("1->find and Replace string\n");
        printf("2->To Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        getchar();
        switch (ch)
        {
        case 1:
            printf("\nEnter the substring: ");
            gets(sub);
            if (findsubstring(string, sub) != -1)
            {
                printf("\nEnter the new substring: ");
                gets(new_str);
                while (findsubstring(string, sub) != -1)
                {
                    replaceSubstring(string, sub, new_str);
                }
                printf("\nThe string after replacing : %s\n", string);
            }
            else
                printf("String is not present\n");
            break;
        case 2:
            printf("\n Exiting\n\n");
            exit(0);
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    }

    return 0;
}