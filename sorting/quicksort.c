#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int partition(int *, int, int);
void quicksort(int *, int, int);
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


    quicksort(arr, 0, n-1);
    printf("\nSorted array: [ ");
    print_arr(arr, n);
    printf("]\n\n");
    return 0;
}

void quicksort(int *arr, int start, int end)
{
    if (start < end)
    {
        int p;
        p = partition(arr, start, end);
        quicksort(arr, start, p-1);
        quicksort(arr, p+1, end);
    }
}

int partition(int *arr, int start, int end)
{
    int temp, l, r, p; 
    p = start;
    l = start;
    r = end;
    while (true)
    {
        while (arr[p] <= arr[r] && r > l)
        {
            r--;
        }

        if (arr[p] > arr[r])
        {
            temp = arr[r];
            arr[r] = arr[p];
            arr[p] = temp;
            p = r;
        }
        else if (r == l)
        {
            return p;
        }

        while (arr[p] >= arr[l] && r > l)
        {
            l++;
        }
        if (arr[p] < arr[l])
        {
            temp = arr[l];
            arr[l] = arr[p];
            arr[p] = temp;
            p = l;
        }
        else if (l == r)
        {
            return p;
        }
    }
    return p;
}


void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
