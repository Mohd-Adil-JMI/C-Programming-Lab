#include <stdio.h>
#include <stdlib.h>

int st;
int percentage(int i, int arr[i][5])
{
    int percentage = (arr[i][2] + arr[i][3] + arr[i][4]) / 3;
    return percentage;
}
int maxins1(int arr[st][5])
{
    int maxs1 = 0;
    for (int i = 0; i < st; i++)
    {
        if (arr[i][2] > maxs1)
        {
            maxs1 = arr[i][2];
        }
    }
    return maxs1;
}
int maxins2(int arr[st][5])
{
    int maxs2 = 0;
    for (int i = 0; i < st; i++)
    {
        if (arr[i][3] > maxs2)
        {
            maxs2 = arr[i][3];
        }
    }
    return maxs2;
}
int maxins3(int arr[st][5])
{
    int maxs3 = 0;
    for (int i = 0; i < st; i++)
    {
        if (arr[i][4] > maxs3)
        {
            maxs3 = arr[i][4];
        }
    }
    return maxs3;
}
int main()
{

    printf("Enter the Number of students: ");
    scanf("%d", &st);
    int arr[st][5];
    for (int i = 0; i < st; i++)
    {
        printf("Enter the roll number age and marks in Subject1 Subject2 and Subject3 of student %d\n", i + 1);
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Roll No.   Age   Subject1   Subject2   Subject3\n");
    for (int i = 0; i < st; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            printf("  %d      ", arr[i][j]);
        }
        printf("\n");
    }

    while (1)
    {
        int ch;
        printf("Enter 1 to display percentage secured by each student\n");
        printf("Enter 2 to display highest marks in each subject\n");
        printf("Enter 3 to display the student who secured highest percentage\n");
        printf("Enter 4 to exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Case 1\n");
            printf("Percentage of Each student\n");
            for (int i = 0; i < st; i++)
            {
                printf("Roll Number:%d secured %d%c\n", arr[i][0], percentage(i, arr), 37);
            }
            break;
        case 2:
            printf("Case 2\n");
            printf("Highest Marks in Each Subject\n");
            printf("Subject1: %d\n", maxins1(arr));
            printf("Subject2: %d\n", maxins2(arr));
            printf("Subject3: %d\n", maxins3(arr));

            break;
        case 3:
            printf("Case 3\n");
            int mp = 0;
            int t = 0;
            for (int i = 0; i < st; i++)
            {
                if (percentage(i, arr) > mp)
                {
                    mp = percentage(i, arr);
                    t = arr[i][0];
                }
            }
            printf("Maximum percentage is %d and secured by roll number %d\n", mp, t);
            break;
        case 4:
            printf("Exiting\n");
            exit(0);
        }
    }
    return 0;
}