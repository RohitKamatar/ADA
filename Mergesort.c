#include <stdio.h>
#include <time.h>

void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = 0;
    int temp[ub - lb + 1];

    while(i <= mid && j <= ub)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= ub)
        temp[k++] = arr[j++];

    for(i = lb, k = 0; i <= ub; i++, k++)
        arr[i] = temp[k];
}

void mergesort(int arr[], int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb + ub) / 2;

        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main()
{
    int n;

    printf("Enter number of elements:");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100000;

    clock_t start, end;

    start = clock();

    mergesort(arr, 0, n - 1);

    end = clock();

    double time_taken = (double)(end - start);

    printf("Time taken to sort %d elements is %f seconds\n", n, time_taken);

    free(arr);
}
