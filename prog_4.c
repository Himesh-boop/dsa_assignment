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

int main(){
    

    return 0;
}