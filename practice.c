#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void insertion(int arr[], int *size, int element, int index)
{
    if (*size >= 10)
    {
        printf("Overflow of an Array\n");
    }
    else
    {
        printf("\nArray after Insertion\n");
        for (int i = *size - 1; i >= 2; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        display(arr, *size);
        *size += 1;
    }
}

int main()
{
    int arr[10] = {1, 2, 9, 10};
    int size = 4;
    display(arr, size);
    for (int i = 10; i > 2; i--)
    {
        insertion(arr, &size, i, 2);
    }
    return 0;
}