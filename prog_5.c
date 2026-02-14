#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

int queue[MAX], front = -1, rear = -1;

void enqueue(int v)
{
    if(rear == MAX-1)
        return;
    if(front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue()
{
    if(front == -1)
        return -1;
    int item = queue[front];
    if(front == rear)
        front = rear = -1;
    else
        front++;
    return item;
}

void BFS(int start)
{
    int i, v;
    for(i=0;i<n;i++)
        visited[i]=0;

    enqueue(start);
    visited[start]=1;

    printf("BFS Traversal: ");

    while(front!=-1)
    {
        v=dequeue();
        printf("%d ",v);

        for(i=0;i<n;i++)
        {
            if(adj[v][i]==1 && visited[i]==0)
            {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
    printf("\n");
}
void DFS(int v)
{
    int i;
    printf("%d ",v);
    visited[v]=1;

    for(i=0;i<n;i++)
    {
        if(adj[v][i]==1 && visited[i]==0)
            DFS(i);
    }
}

int main()
{
    int i,j,start;

    n=5;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adj[i][j]=0;

    adj[0][1]=adj[1][0]=1;
    adj[0][2]=adj[2][0]=1;
    adj[1][3]=adj[3][1]=1;
    adj[1][4]=adj[4][1]=1;
    adj[2][4]=adj[4][2]=1;

    start=0;

    BFS(start);

    for(i=0;i<n;i++)
        visited[i]=0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}