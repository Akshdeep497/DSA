#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int arr2[100];
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            arr2[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        arr2[k] = arr[i];
        i++;
        k++;
        printf("func 2\n");
    }
    while (j <= high)
    {
        arr2[k] = arr[j];
        j++;
        k++;
        printf("func 3\n");
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = arr2[i];
    }
}
void mergesort(int *arr, int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void printarray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 45, 7, 3, 13, 5, 6};
    mergesort(arr, 0, 7);

    int size = 8;
    printarray(arr, 8);
}
