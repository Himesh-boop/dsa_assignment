#include <stdio.h>
#define MAX 10
#define INF 9999

int minDistance(int dist[], int visited[], int n)
{
    int min = INF, min_index = -1;
    int i;

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int source)
{
    int dist[MAX];
    int visited[MAX];
    int i, j, u;

    for(i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(i = 0; i < n - 1; i++)
    {
        u = minDistance(dist, visited, n);
        visited[u] = 1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && graph[u][j] != 0 &&
               dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main()
{
    int graph[MAX][MAX] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int n = 5;
    int source = 0;

    dijkstra(graph, n, source);

    return 0;
}
