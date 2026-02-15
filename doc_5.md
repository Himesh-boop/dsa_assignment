# Documentation for prog_5.c

## (a) Data Structures

**Graph Representation:**
- `int adj[MAX][MAX]`: Adjacency matrix to represent graph connections (1 for edge, 0 for no edge)
- `int visited[MAX]`: Array to track visited vertices during traversal (1 for visited, 0 for unvisited)
- `int n`: Number of vertices in the graph

**Queue for BFS:**
- `int queue[MAX]`: Array-based queue to store vertices for BFS traversal
- `int front`: Index of the front element in queue (-1 when empty)
- `int rear`: Index of the rear element in queue (-1 when empty)

## (b) Functions

**`void enqueue(int v)`**
- Adds a vertex to the rear of the queue
- Initializes front to 0 if queue was empty
- Increments rear and stores the vertex

**`int dequeue()`**
- Removes and returns the vertex from the front of the queue
- Returns -1 if queue is empty
- Resets front and rear to -1 if queue becomes empty after dequeue

**`void BFS(int start)`**
- Performs Breadth-First Search traversal starting from given vertex
- Initializes all vertices as unvisited, then enqueues start vertex
- Dequeues vertices, prints them, and enqueues unvisited adjacent vertices

**`void DFS(int v)`**
- Performs Depth-First Search traversal recursively from given vertex
- Marks current vertex as visited and prints it
- Recursively visits all unvisited adjacent vertices

## (c) Main Method Organization

1. Declares variables and sets number of vertices (n=5)
2. Initializes adjacency matrix to all zeros (no edges)
3. Creates edges by setting adjacency matrix values to 1 for connected vertices:
   - 0-1, 0-2, 1-3, 1-4, 2-4
4. Sets starting vertex to 0
5. Calls BFS(start) to perform breadth-first traversal
6. Resets visited array to all zeros
7. Calls DFS(start) to perform depth-first traversal

## (d) Sample Output

```
BFS Traversal: 0 1 2 3 4 
DFS Traversal: 0 1 3 4 2 
```