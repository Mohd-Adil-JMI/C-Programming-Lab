#include <stdio.h>
#define max __INT_MAX__

int main()
{
    int n;
    printf("Enter size of an Array -> ");
    scanf("%d", &n);
    printf("Enter Elements -> ");
    int arr[n];
    int start;
    int end;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = max; //initialising sum with max value of int
    int temp;
    for (int i = 1; i <= n; i++) //grouping no. of elements
    {
        for (int j = 0; j <= n - i; j++) //iterating through these continous groups
        {
            temp = 0;
            for (int k = j; k < j + i; k++) //iterating through elements of particular group
            {
                temp += arr[k];
            }
            if (temp <= sum)
            {
                start=j;
                end=i+j;
                sum = temp; //using minimum sum
            }
        }
    }
    printf("SubArray -> ");
    for (int i = start; i < end; i++)
    {
        printf("%d ",arr[i]);
    }
    
    printf("\nMinimum sum -> %d\n\n", sum);
    return 0;
}