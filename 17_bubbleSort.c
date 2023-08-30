#include <stdio.h>
#include <stdlib.h>
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}
void bubblesort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        printf("pass %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void bubblesortadaptive(int arr[], int size)
{
    int temp;
    int sorted;
    for (int i = 0; i < size - 1; i++)
    {
        printf("pass %d\n", i + 1);

        for (int j = 0; j < size - 1 - i; j++)
        {
            sorted = 1;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 0;
            }
        }
        if (sorted)
        {
            return;
        }
    }
}
int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 8};
    int size = 8;
    // bubblesort(arr,size);
    bubblesortadaptive(arr, size);
    print(arr, size);
}
