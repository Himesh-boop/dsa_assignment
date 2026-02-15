# Documentation for prog_8.c

## (a) Data Structures

**Dynamic Arrays:**
- `int *arr`: Dynamically allocated array to store numbers for sorting
- `int *original`: Dynamically allocated array to store original unsorted numbers
- `int n`: Size of the array (user input)

**Performance Counters:**
- `int comparisons`: Global counter tracking total number of comparisons made
- `int swaps`: Global counter tracking total number of swaps made

**Temporary Arrays (for Merge Sort):**
- `int *L`: Left subarray for merging
- `int *R`: Right subarray for merging

## (b) Functions

**`void bubbleSort(int arr[], int n)`**
- Implements bubble sort algorithm
- Compares adjacent elements and swaps if in wrong order
- Counts comparisons and swaps

**`void selectionSort(int arr[], int n)`**
- Implements selection sort algorithm
- Finds minimum element and places it at correct position
- Counts comparisons and swaps

**`void insertionSort(int arr[], int n)`**
- Implements insertion sort algorithm
- Builds sorted array by inserting elements at correct positions
- Counts comparisons and swaps

**`void merge(int arr[], int l, int m, int r)`**
- Merges two sorted subarrays into one sorted array
- Uses temporary arrays L and R for merging
- Counts comparisons during merge process

**`void mergeSortHelper(int arr[], int l, int r)`**
- Recursive helper function for merge sort
- Divides array into halves and calls merge to combine them

**`void mergeSort(int arr[], int n)`**
- Wrapper function that calls mergeSortHelper with initial parameters

**`void printArray(int arr[], int n)`**
- Prints all elements of the array
- Displays array contents before and after sorting

## (c) Main Method Organization

1. Prompts user to enter the size of array (N)
2. Dynamically allocates memory for arr and original arrays
3. Generates N random numbers between 1 and 1000 using rand()
4. Stores numbers in both arr and original arrays
5. Displays menu with 4 sorting algorithm options
6. Takes user's choice of sorting algorithm
7. Displays unsorted array
8. Resets comparison and swap counters to 0
9. Executes chosen sorting algorithm on arr
10. Displays sorted array
11. Displays total comparisons and swaps (swaps not applicable for merge sort)
12. Frees dynamically allocated memory

## (d) Sample Output

```
Enter the value of N: 10

Choose a sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter your choice (1-4): 1

Numbers before sorting:
456 789 123 654 321 987 234 567 890 111 

Using Bubble Sort

Numbers after sorting:
111 123 234 321 456 567 654 789 890 987 

Total comparisons: 45
Total swaps: 21
```