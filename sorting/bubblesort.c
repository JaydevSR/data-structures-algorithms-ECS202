#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void bubblesort(int *, int, int);
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


    bubblesort(arr, 0, n-1);
    printf("\nSorted array: [ ");
    print_arr(arr, n);
    printf("]\n\n");
    return 0;
}


void bubblesort(int *arr, int start, int end)
{
    int temp;
    for (int i=end; i>start; i--)
    {
        for (int j=start; j<i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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