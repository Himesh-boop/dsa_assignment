# Documentation for prog_4.c

## (a) Data Structures

**Node Structure:**
- `int data`: Stores the integer value of the node
- `struct Node* prev`: Pointer to the previous node in the doubly linked list
- `struct Node* next`: Pointer to the next node in the doubly linked list

**Doubly Linked List:**
- `struct Node* head`: Pointer to the first node of the doubly linked list (NULL if empty)

## (b) Functions

**`struct Node* createNode(int data)`**
- Creates a new node with the given data
- Allocates memory and initializes data, prev, and next pointers to NULL
- Returns pointer to the newly created node

**`void insertAfter(struct Node* given, int data)`**
- Inserts a new node after the given node
- Updates the next and prev pointers of surrounding nodes
- Handles cases where given node is at the end

**`struct Node* deleteNode(struct Node* head, struct Node* del)`**
- Deletes the specified node from the doubly linked list
- Updates prev and next pointers of adjacent nodes
- Frees the memory of deleted node and returns updated head

**`void display(struct Node* head)`**
- Prints all elements in the doubly linked list from head to end
- Traverses the list and prints each node's data

## (c) Main Method Organization

1. Creates three nodes with values 10, 20, 30 and links them manually
2. Sets up prev and next pointers to form a doubly linked list
3. Displays the original list
4. Calls insertAfter() to insert 25 after node with value 20
5. Displays the list after insertion
6. Calls deleteNode() to delete the node with value 20
7. Displays the list after deletion

## (d) Sample Output

```
Original list:
10 20 30 
After inserting 25 after 20:
10 20 25 30 
After deleting 20:
10 25 30 
```