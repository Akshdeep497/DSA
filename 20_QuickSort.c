#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int low, int high)
{
    int temp;
    int pivot = low;
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= arr[pivot])
        {
            i++;
        }
        while (arr[j] > arr[pivot])
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    return j;
}
void printarray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void quicksort(int *arr, int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        quicksort(arr, low, partitionindex - 1);
        quicksort(arr, partitionindex + 1, high);
    }
}

int main()
{
    int arr[] = {1, 2, 45, 7, 3, 13, 5, 6};
    quicksort(arr, 0, 7);
    int size = 8;
    printarray(arr, 8);
}
