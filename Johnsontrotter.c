#include <stdio.h>
#define LEFT -1
#define RIGHT 1

void printPermutation(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int getMobile(int a[], int dir[], int n)
{
    int mobile = 0, mobileIndex = -1;

    for(int i = 0; i < n; i++)
    {
        if(dir[i] == LEFT && i > 0 &&
           a[i] > a[i - 1] &&
           a[i] > mobile)
        {
            mobile = a[i];
            mobileIndex = i;
        }

        if(dir[i] == RIGHT && i < n - 1 &&
           a[i] > a[i + 1] &&
           a[i] > mobile)
        {
            mobile = a[i];
            mobileIndex = i;
        }
    }

    return mobileIndex;
}

void JohnsonTrotter(int n)
{
    int a[20], dir[20];

    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    while(1)
    {
        int m = getMobile(a, dir, n);

        if(m == -1)
            break;

        int swapIndex;

        if(dir[m] == LEFT)
            swapIndex = m - 1;
        else
            swapIndex = m + 1;

        int temp = a[m];
        a[m] = a[swapIndex];
        a[swapIndex] = temp;

        temp = dir[m];
        dir[m] = dir[swapIndex];
        dir[swapIndex] = temp;

        m = swapIndex;

        for(int i = 0; i < n; i++)
        {
            if(a[i] > a[m])
                dir[i] = !dir[i];
        }

        printPermutation(a, n);
    }
}

int main()
{
    int n;

    printf("Enter n");
    scanf("%d", &n);

    JohnsonTrotter(n);

    return 0;
}
