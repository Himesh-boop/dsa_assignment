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

int main(){
    

    return 0;
}