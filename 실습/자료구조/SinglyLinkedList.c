#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    newNode->next = *head;
    *head = newNode;
}

void insertAfter(struct Node* givenNode, int newData) {
    if (givenNode == NULL) {
        printf("ERROR: givenNode is NULL\n");
        return;
    }
    struct Node* newNode = createNode(newData);
    newNode->next = givenNode->next;
    givenNode->next = newNode;
}

void insertEnd(struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("ERROR: Node with key %d not found\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertBeginning(&head, 1);
    insertBeginning(&head, 2);
    printList(head);
    insertAfter(head, 3);
    printList(head);
    insertEnd(&head, 10);
    insertEnd(&head, 11);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    deleteNode(&head, 5);
    return 0;
}
