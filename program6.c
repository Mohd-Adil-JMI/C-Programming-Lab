#include <stdio.h>
#include <stdlib.h>

char string[100];
int strlength(char string[])
{
    int count = 0;
    while (string[count] != '\0')
    {
        count++;
    }
    return count;
}
void reverse(char string[])
{
    int len = strlength(string);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temp;
    }
    printf("The reversed string is %s\n", string);
}

void strcopy(char string[], char new[])
{
    int len = strlength(string);
    int i;
    for (i = 0; i < len; i++)
    {
        new[i] = string[i];
    }
    new[i] = '\0';
    printf("String Copied-> %s\n", new);
}
void strcompare(char string1[], char string2[])
{
    int len1 = strlength(string1);
    int len2 = strlength(string2);
    if (len1 != len2)
    {
        printf("Strings are not Equal\n");
    }
    else
    {
        int flag;
        for (int i = 0; i < len1; i++)
        {
            if (string1[i] == string2[i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if (flag == 0)
        {
            printf("Strings are not Equal\n");
        }
        else
        {
            printf("Strings are Equal\n");
        }
    }
}
void strappend(char string[], char Append[])
{
    int len = strlength(string);
    int len1 = strlength(Append);
    int i;
    for (i = 0; i < len1; i++)
    {
        string[len + i] = Append[i];
    }
    string[len + i] = '\0';
    printf("The new string is %s\n", string);
}
void checkpalindrome(char string[])
{
    int len = strlength(string);
    int flag;
    for (int i = 0; i < len / 2; i++)
    {
        if (string[i] == string[len - i - 1])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

int findsubstring(char string[], char substring[])
{
    int m = strlength(string);
    int n = strlength(substring);
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
int main()
{
    while (1)
    {
        int ch;
        printf("\n1->String Length\n");
        printf("2->To reverse a string\n");
        printf("3->To copy one string to another\n");
        printf("4->To compare two strings\n");
        printf("5->To Append one string to another\n");
        printf("6->Palindrome\n");
        printf("7->Search Substring\n");
        printf("8->To Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        getchar();
        switch (ch)
        {
        case 1:
            printf("Case 1\n\n");
            printf("Enter the string: ");
            gets(string);
            printf("Length is %d\n", strlength(string));
            break;
        case 2:
            printf("Case 2\n\n");
            printf("Enter the string: ");
            gets(string);
            reverse(string);
            break;
        case 3:
            printf("Case 3\n\n");
            printf("Enter the string: ");
            gets(string);
            char new[100];
            strcopy(string, new);
            break;
        case 4:
            printf("Case 4\n\n");
            printf("Enter the string1: ");
            char string1[100];
            gets(string1);
            printf("Enter the string2: ");
            char string2[100];
            gets(string2);
            strcompare(string1, string2);
            break;
        case 5:
            printf("Case 5\n\n");
            printf("Enter the string: ");
            gets(string);
            printf("Enter the new string to append: ");
            char Add[100];
            gets(Add);
            strappend(string, Add);
            break;
        case 6:
            printf("Case 6\n\n");
            printf("Enter the string: ");
            gets(string);
            checkpalindrome(string);
            break;
        case 7:
            printf("Case 7\n\n");
            printf("Enter the string: ");
            gets(string);
            printf("Enter the substring: ");
            char substring[100];
            gets(substring);
            if (findsubstring(string,substring)!=-1)
                printf("\"%s\" is a substring of \"%s\" at index %d\n",substring,string,findsubstring(string,substring));
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