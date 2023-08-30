#include <stdio.h>
void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
};

void selectionsort(int *arr, int size)
{
    int minindex;
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        minindex = i;
        printf("pass %d\n", i + 1);

        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                minindex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
        printarray(arr, size);
    }
}
int main()
{
    int arr[] = {1, 4, 3, 6, 4, 5, 7, 3, 5};
    int size = 9;
    selectionsort(arr, size);

    printarray(arr, 9);

    return 0;
}
