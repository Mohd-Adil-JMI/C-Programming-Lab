#include <stdio.h>
#include <stdlib.h>
void add(int r1, int c1, int r2, int c2, int matrix1[r1][c1], int matrix2[r2][c2])
{
    if (r1 != r2 || c1 != c2)
    {
        printf("Addition not possible");
    }
    //adding
    int c[r1][c1];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            c[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    // printing sum matrix
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
void sub(int r1, int c1, int r2, int c2, int matrix1[r1][c1], int matrix2[r2][c2])
{
    if (r1 != r2 || c1 != c2)
    {
        printf("Addition not possible");
    }
    //adding
    int c[r1][c1];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            c[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    // printing sub matrix
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}
void mult(int r1, int c1, int r2, int c2, int matrix1[r1][c1], int matrix2[r2][c2])
{
    if (c1 != r2)
    {
        printf("Multiplication not possible");
    }
    int c[r1][c2];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                c[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    // printing mult matrix
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
};

int main()
{
    int r1, c1;
    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &r1);
    printf("Enter the number of columns for matrix 1: ");
    scanf("%d", &c1);
    int matrix1[r1][c1];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Input element's value: ");
            scanf("%d", &matrix1[i][j]);
        }
    }

    int r2, c2;
    printf("Enter the number of rows for matrix 2: ");
    scanf("%d", &r2);
    printf("Enter the number of columns for matrix 2: ");
    scanf("%d", &c2);
    int matrix2[r2][c2];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Input element's value: ");
            scanf("%d", &matrix2[i][j]);
        }
    }
    //printing matrices
    printf("\nMatrix 1:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    while (1)
    {
        int ch;
        printf("Enter 1 for Addition\n");
        printf("Enter 2 for Substraction\n");
        printf("Enter 3 for Multiplication\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Adding Matrices\n");
            add(r1, c1, r2, c2, matrix1, matrix2);
            break;
        case 2:
            printf("Substracting Matrices\n");
            sub(r1, c1, r2, c2, matrix1, matrix2);
            break;
        case 3:
            printf("Multiplying Matrices\n");
            mult(r1, c1, r2, c2, matrix1, matrix2);
            break;
        case 4:
            printf("Exiting\n");
            exit(0);
        default:
            printf("Invalid Input\n");
        }
    }

    return 0;
}
