# Documentation for prog_6.c

## (a) Data Structures

**Array-based Heap:**
- `int arr[]`: Array representation of the heap
- `int n`: Number of elements in the heap

**Heap Properties:**
- Max Heap: Parent node is greater than or equal to its children
- Min Heap: Parent node is less than or equal to its children
- For any node at index i:
  - Left child at index: 2*i + 1
  - Right child at index: 2*i + 2

## (b) Functions

**`void swap(int *a, int *b)`**
- Swaps the values of two integers
- Uses a temporary variable to exchange values

**`void maxHeapify(int arr[], int n, int i)`**
- Maintains max heap property for a subtree rooted at index i
- Finds largest among node and its children
- Recursively heapifies if largest is not the root

**`void buildMaxHeap(int arr[], int n)`**
- Builds a max heap from an unsorted array
- Calls maxHeapify for all non-leaf nodes from bottom to top

**`void minHeapify(int arr[], int n, int i)`**
- Maintains min heap property for a subtree rooted at index i
- Finds smallest among node and its children
- Recursively heapifies if smallest is not the root

**`void buildMinHeap(int arr[], int n)`**
- Builds a min heap from an unsorted array
- Calls minHeapify for all non-leaf nodes from bottom to top

**`void printArray(int arr[], int n)`**
- Prints all elements of the array
- Displays the heap structure in array form

## (c) Main Method Organization

1. Declares two identical arrays with values {40, 10, 30, 50, 60, 15}
2. Sets array size to 6
3. Calls buildMaxHeap() on first array to create a max heap
4. Prints the max heap array
5. Calls buildMinHeap() on second array to create a min heap
6. Prints the min heap array

## (d) Sample Output

```
Max Heap:
60 50 40 10 30 15 
Min Heap:
10 40 15 50 60 30 
```