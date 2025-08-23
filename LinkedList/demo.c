#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
   
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        return newNode;
    }
}

// Function to insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    } else {
        struct Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        return head;
    }
}

// Function to insert at a specific position
struct Node* insertAtPosition(struct Node* head, int position, int data) {
    if (position == 1) {
        return insertAtBeginning(head, data);
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = head;
    int i;
    for (i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && i < position - 1) {
        printf("Position out of range\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != head) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

// Function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function with menu
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        // Display the menu
        printf("\nCircular Doubly Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Print List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;

            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter data to insert at position %d: ", position);
                scanf("%d", &data);
                head = insertAtPosition(head, position, data);
                break;

            case 4:
                printList(head);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}