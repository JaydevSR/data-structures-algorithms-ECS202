#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void selectionsort(int *, int, int);
void print_arr(int *, int);


int main()
{
    int n, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter the elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        arr[i] = temp;
    }

    printf("\nUnsorted array: [ ");
    print_arr(arr, n);
    printf("]\n");


    selectionsort(arr, 0, n-1);
    printf("\nSorted array: [ ");
    print_arr(arr, n);
    printf("]\n\n");
    return 0;
}


void selectionsort(int *arr, int start, int end)
{
    int i = start, j, key, min;
    while (i<end)
    {
        j = i+1;
        key = i;
        min = arr[i];
        while (j<=end)
        {
            if (arr[j]<min)
            {
                min = arr[j];
                key = j;
            }
            j++;
        }
        arr[key] = arr[i];
        arr[i] = min;
        i++;
    }
}

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}