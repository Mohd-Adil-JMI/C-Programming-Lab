#include <stdio.h>
#include <stdlib.h>

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
            printf("%d ", Matrix[k][i]); //printing first row and increamenting k(first row) to the next row
        }
        k++;
        for (int i = k; i <= last_row; i++)
        {
            printf("%d ", Matrix[i][last_col]); //printing remaining elements of last column and decreamenting it to the previous column
        }
        last_col--;
        if (k <= last_row)
        {
           // for (int i = last_col; i >= l; i--)
           // {
            //    printf("%d ", Matrix[last_row][i]); //printing remaining elements of last row and decreamenting the last_row to the previous row
           // }
            for (int i = l; i <= last_col; i++)
            {
                if (l==0)
                {
                    printf("%d ", Matrix[last_row][last_col-i]);
                }
                else{
                    printf("%d ", Matrix[last_row][last_col-i+1]);
                }
                
                 //printing remaining elements of last row and decreamenting the last_row to the previous row
            }
            last_row--;
        }
        if (l <= last_col)
        {
            for (int i = last_row; i >= k; i--) 
            {
                printf("%d ", Matrix[i][l]); //now the remaining side is first column and we have to move from bottom to top so by the
                                             // help of decrement loop we print the remaining values and increament the l(firt column) to the next column.
                                             //now we get the new inner 2d matrix and we will repeat the same process.
            }
            l++;
        }
    }
}
int main()
{
    int r,c;
    printf("Enter Rows: ");
    scanf("%d", &r);
    printf("Enter Columns: ");
    scanf("%d", &c);
    int* Matrix=(int*)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++)
        Matrix[i] = (int*)malloc(c * sizeof(int));
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