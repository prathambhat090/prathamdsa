#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if(head != NULL)
        head->prev = newNode;

    newNode->next = head;
    head = newNode;

    return head;
}
struct Node* insertEnd(struct Node* head, int data) {

    struct Node* newNode = createNode(data);

    if(head == NULL)
        return newNode;

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}
struct Node* insertAtPosition(struct Node* head, int data, int pos) {

    struct Node* newNode = createNode(data);

    // Insert at beginning
    if(pos == 1) {
        newNode->next = head;

        if(head != NULL)
            head->prev = newNode;

        head = newNode;
        return head;
    }

    struct Node* temp = head;

    // Traverse to (pos-1)
    for(int i = 1; temp != NULL && i < pos-1; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position out of range\n");
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}