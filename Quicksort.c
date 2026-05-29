#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int random = low + rand() % (high - low);

    swap(&arr[random], &arr[high]);

    int pivot;
}

int main()
{
    int n;

    printf("Enter number of elements:");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    clock_t start = clock();
    quicksort(arr, 0, n - 1);

    clock_t end = clock();

    double time_taken = (double)(end - start) /
                        CLOCKS_PER_SEC;

    printf("Time taken for %d elements is %f",
           n, time_taken);

    free(arr);

    return 0;
}
