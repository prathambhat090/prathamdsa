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
struct Node* deleteBeginning(struct Node* head) {

    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);

    return head;
}
struct Node* deleteEnd(struct Node* head) {

    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* temp = head;

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    free(temp);

    return head;
}
struct Node* deleteAtPosition(struct Node* head, int pos) {

    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    if(pos == 1) {
        head = head->next;

        if(head != NULL)
            head->prev = NULL;

        free(temp);
        return head;
    }
    for(int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Position out of range\n");
        return head;
    }
    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    return head;
}