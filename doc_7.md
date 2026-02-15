# Documentation for prog_7.c

## (a) Data Structures

**Graph Representation:**
- `int graph[MAX][MAX]`: Adjacency matrix representing weighted graph (0 means no edge)
- `int n`: Number of vertices in the graph

**Algorithm Arrays:**
- `int dist[MAX]`: Stores shortest distance from source to each vertex
- `int visited[MAX]`: Tracks whether a vertex has been processed (1 for visited, 0 for unvisited)

**Constants:**
- `MAX`: Maximum number of vertices (10)
- `INF`: Represents infinity (9999) for unreachable vertices

## (b) Functions

**`int minDistance(int dist[], int visited[], int n)`**
- Finds the unvisited vertex with minimum distance value
- Returns the index of vertex with minimum distance
- Returns -1 if no unvisited vertex found

**`void dijkstra(int graph[MAX][MAX], int n, int source)`**
- Implements Dijkstra's algorithm to find shortest paths from source vertex
- Initializes all distances to INF and visited array to 0
- Sets source distance to 0 and iteratively selects minimum distance vertex
- Updates distances of adjacent unvisited vertices if shorter path found
- Prints final shortest distances from source to all vertices

## (c) Main Method Organization

1. Declares and initializes a weighted graph as adjacency matrix with 5 vertices
2. Edge weights represent distances between vertices (0 means no direct edge)
3. Sets number of vertices to 5 and source vertex to 0
4. Calls dijkstra() to compute shortest paths from source
5. Results are printed inside the dijkstra function

## (d) Sample Output

```
Vertex	Distance from Source
0	0
1	10
2	50
3	30
4	60
```