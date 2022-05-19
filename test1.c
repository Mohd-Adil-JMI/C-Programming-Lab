#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int findsubstring(char string[], char substring[]);
void replaceSubstring(char[], char[], char[]);
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
                replaceSubstring(string, sub, new_str);
                printf("\nThe string after replacing : %s\n",

                       string);
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
    int stringLen, subLen, newLen;
    int i = 0, j, k;
    int flag = 0, start, end;
    stringLen = strlen(string);
    subLen = strlen(sub);
    newLen = strlen(new_str);
    for (i = 0; i < stringLen; i++)
    {
        flag = 0;

        start = i;
        for (j = 0; string[i] == sub[j]; j++, i++)
            if (j == subLen - 1)
                flag = 1;

        end = i;
        if (flag == 0)
            i -= j;
        else
        {
            for (j = start; j < end; j++)
            {
                for (k = start; k < stringLen; k++)
                    string[k] = string[k + 1];
                stringLen--;
                i--;
            }
            for (j = start; j < start + newLen; j++)
            {
                for (k = stringLen; k >= j; k--)
                    string[k + 1] = string[k];
                string[j] = new_str[j - start];
                stringLen++;
                i++;
            }
        }
    }
}