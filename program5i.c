/*Write a C program to print a given 2d matrix in a helical order. (Order of

the matrix should be given by the user)
*/

#include <stdio.h>
#include <stdlib.h>
int r, c;
void display(int Matrix[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (Matrix[i][j] < 10)
            {
                printf(" %d ", Matrix[i][j]);
            }
            else
            {
                printf("%d ", Matrix[i][j]);
            }
        }
        printf("\n");
    }
}
void helical(int Matrix[r][c])
{
    int k = 0, l = 0;
    int last_row = r - 1, last_col = c - 1;
    printf("Result: ");
    while (k <= last_row && l <= last_col)
    {
        for (int i = l; i <= last_col; i++)
        {
            printf("%d ", Matrix[k][i]);
        }
        k++;
        for (int i = k; i <= last_row; i++)
        {
            printf("%d ", Matrix[i][last_col]);
        }
        last_col--;
        if (k <= last_row)
        {
            for (int i = last_col; i >= l; i--)
            {
                printf("%d ", Matrix[last_row][i]);
            }
            last_row--;
        }
        if (l <= last_col)
        {
            for (int i = last_row; i >= k; i--)
            {
                printf("%d ", Matrix[i][l]);
            }
            l++;
        }
    }
}
int main()
{
    printf("Enter Rows: ");
    scanf("%d", &r);
    printf("Enter Columns: ");
    scanf("%d", &c);
    int Matrix[r][c];
    for (int i = 0; i < r; i++)
    {
        printf("Input element's of %d row: ", i + 1);
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &Matrix[i][j]);
        }
    }
    display(Matrix);
    helical(Matrix);
    return 0;
}
