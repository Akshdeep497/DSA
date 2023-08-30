#include <stdio.h>
#include <stdlib.h>

int maximum(int *arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
void countsort(int *arr, int size)
{
    int max = maximum(arr, size);

    int count[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    // printarray(count,max+1);
    int i = 0;
    int j = 0;
    while (j <= max)
    {
        if (count[j] > 0)
        {
            arr[i] = j;
            count[j]--;
            i++;
        }
        else
        {
            j++;
        }
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
    countsort(arr, 8);

    int size = 8;
    // printf("%d\n",maximum(arr,8));
    printarray(arr, 8);
}
