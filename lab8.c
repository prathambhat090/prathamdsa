struct Node* insertBeginning(struct Node* head, int data) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return head;
    }

    struct Node* temp = head;

    while(temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;

    return head;
}

struct Node* insertEnd(struct Node* head, int data) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;

    while(temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(position == 1) {
        return insertBeginning(head, data);
    }

    struct Node* temp = head;
    int count = 1;

    while(count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if(count == position - 1) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Position out of bounds\n");
        free(newNode);
    }

    return head;
}

struct Node* deleteBeginning(struct Node* head) {

    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if(head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;

    while(temp->next != head) {
        temp = temp->next;
    }

    struct Node* toDelete = head;
    temp->next = head->next;
    head = head->next;

    free(toDelete);
    return head;
}

struct Node* deleteEnd(struct Node* head) {

    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if(head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;

    while(temp->next->next != head) {
        temp = temp->next;
    }

    struct Node* toDelete = temp->next;
    temp->next = head;

    free(toDelete);
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position) {

    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if(position == 1) {
        return deleteBeginning(head);
    }

    struct Node* temp = head;
    int count = 1;

    while(count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if(count == position - 1 && temp->next != head) {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    } else {
        printf("Position out of bounds\n");
    }

    return head;
}