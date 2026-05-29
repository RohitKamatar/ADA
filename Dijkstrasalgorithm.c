#include <stdio.h>

#define INF 9999

int minDistance(int dist[], int visited[], int n)
{
    int min = INF, index;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int graph[50][50], int n, int source)
{
    int dist[50], visited[50];

    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(int count = 0; count < n; count++)
    {
        int u = minDistance(dist, visited, n);

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] &&
               graph[u][v] != 0 &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distance from vertex %d\n", source);

    for(int i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main()
{
    int n, source;
    int graph[10][10];

    printf("Enter number of vertices:");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex:");
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}
