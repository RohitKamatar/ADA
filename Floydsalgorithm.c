#include <stdio.h>
#define INF 99

void floydWarshall(int n, int dist[n][n])
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void printMatrix(int n, int dist[n][n])
{
    printf("\nShortest distance matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] >= INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter number of vertices:");
    scanf("%d", &n);

    int dist[n][n];

    printf("Enter adjacency matrix:\n");
    printf("(Use %d for INF if no edge)\n", INF);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }

    floydWarshall(n, dist);

    printMatrix(n, dist);

    return 0;
}
