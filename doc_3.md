# Documentation for prog_3.c

## (a) Data Structures

**Node Structure:**
- `int data`: Stores the integer value of the node
- `struct Node* next`: Pointer to the next node in the linked list

**Linked List:**
- `struct Node* head`: Pointer to the first node of the linked list (NULL if empty)

## (b) Functions

**`struct Node* createNode(int data)`**
- Creates a new node with the given data
- Allocates memory for the node and initializes data and next pointer
- Returns pointer to the newly created node

**`struct Node* insertEnd(struct Node* head, int data)`**
- Inserts a new node at the end of the linked list
- Creates a new node and traverses to the last node
- Returns the head of the list

**`void reverseTraversal(struct Node* head)`**
- Prints the linked list in reverse order using recursion
- Recursively calls itself until reaching the end (NULL)
- Prints node data while returning from recursion

## (c) Main Method Organization

1. Declares head pointer and initializes it to NULL
2. Inserts five nodes with values 10, 20, 30, 40, 50 using insertEnd()
3. Prints "Reverse traversal:" message
4. Calls reverseTraversal() to display list in reverse order

## (d) Sample Output

```
Reverse traversal:
50 40 30 20 10
```