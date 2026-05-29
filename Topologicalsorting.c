#include <stdio.h>
#define MAX 100

int main()
{
    int n, v[MAX][MAX];
    int indegree[MAX], visited[MAX];
    int TP[MAX], tpcount = 0;

    printf("Enter number of vertices:");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        indegree[i] = 0;

        for(int j = 0; j < n; j++)
        {
            if(v[j][i] == 1)
            {
                indegree[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    while(1)
    {
        int w = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 0 && indegree[i] == 0)
            {
                w = i;
                break;
            }
        }

        if(w == -1)
            break;

        TP[tpcount++] = w;
        visited[w] = 1;

        for(int i = 0; i < n; i++)
        {
            if(v[w][i] == 1)
            {
                indegree[i]--;
            }
        }
    }

    if(tpcount < n)
    {
        printf("No Topological Sequence\n");
    }
    else
    {
        printf("Topological order:\n");

        for(int i = 0; i < tpcount; i++)
        {
            printf("%d ", TP[i]);
        }

        printf("\n");
    }

    return 0;
}
