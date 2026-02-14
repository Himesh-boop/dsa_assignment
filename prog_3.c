#include <stdio.h>
#include <stdlib.h>

// Write and implement reverse traversal algorithm in linked list. Write main() to demonstrate the use of the function

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data)
{
    struct Node* newNode = createNode(data);

    if(head == NULL)
        return newNode;

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

void reverseTraversal(struct Node* head)
{
    if(head == NULL)
        return;

    reverseTraversal(head->next);

    printf("%d ", head->data);
}

int main()
{
    struct Node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    printf("Reverse traversal:\n");

    reverseTraversal(head);

    return 0;
}
