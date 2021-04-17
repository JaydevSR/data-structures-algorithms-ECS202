#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void insertionsort(int *, int, int);
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


    insertionsort(arr, 0, n-1);
    printf("\nSorted array: [ ");
    print_arr(arr, n);
    printf("]\n\n");
    return 0;
}


void insertionsort(int *arr, int start, int end)
{
    int low = start, high = start, temp;
    for (int i=start + 1; i<=end; i++)
    {
        int temp = arr[i];
        for (int j = i-1; j>=start && arr[j] > temp; j--)
        {
            arr[j+1] = arr[j];
            arr[j] = temp;
        }
    }
}

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}