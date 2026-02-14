#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(struct Node* given, int data)
{
    if(given == NULL)
        return;

    struct Node* newNode = createNode(data);

    newNode->next = given->next;
    newNode->prev = given;

    if(given->next != NULL)
        given->next->prev = newNode;

    given->next = newNode;
}

struct Node* deleteNode(struct Node* head, struct Node* del)
{
    if(head == NULL || del == NULL)
        return head;

    if(head == del)
        head = del->next;

    if(del->next != NULL)
        del->next->prev = del->prev;

    if(del->prev != NULL)
        del->prev->next = del->next;

    free(del);

    return head;
}

void display(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Original list:\n");
    display(head);

    insertAfter(second, 25);

    printf("After inserting 25 after 20:\n");
    display(head);

    head = deleteNode(head, second);

    printf("After deleting 20:\n");
    display(head);

    return 0;
}