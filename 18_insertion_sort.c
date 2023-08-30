#include <stdio.h>
void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
};
void insertionsort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {1, 4, 3, 6, 4, 5, 7, 3, 5};
    int size = 9;
    insertionsort(arr, size);
    printarray(arr, 9);

    return 0;
}
