#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
struct node* insertAtBeginning(struct node* head, int val) {
    struct node* newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

// Insert at end
struct node* insertAtEnd(struct node* head, int val) {
    struct node* newNode = createNode(val);
    if (head == NULL) return newNode;

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Insert at specific position
struct node* insertAtPosition(struct node* head, int val, int position) {
    struct node* newNode = createNode(val);

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete from beginning
struct node* deleteBeginning(struct node* head) {
    if (head == NULL) {
        printf("List empty.\n");
        return head;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete from end
struct node* deleteEnd(struct node* head) {
    if (head == NULL) {
        printf("List empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete from specific position
struct node* deletePosition(struct node* head, int position) {
    if (head == NULL) {
        printf("List empty.\n");
        return head;
    }

    if (position == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    struct node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    return head;
}

// Display list
void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse list
struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Concatenate two lists
struct node* concatLists(struct node* head1, struct node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

// Main menu
int main() {
    struct node* head = NULL;
    int choice, val, pos;

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display list\n");
        printf("8. Reverse list\n");
        printf("9. Concatenate with another list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                head = insertAtBeginning(head, val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                head = insertAtEnd(head, val);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertAtPosition(head, val, pos);
                break;

            case 4:
                head = deleteBeginning(head);
                break;

            case 5:
                head = deleteEnd(head);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deletePosition(head, pos);
                break;

            case 7:
                display(head);
                break;

            case 8:
                head = reverseList(head);
                printf("List reversed.\n");
                break;

            case 9: {
                struct node* head2 = NULL;
                int n, v;
                printf("Enter number of elements for second list: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &v);
                    head2 = insertAtEnd(head2, v);
                }
                head = concatLists(head, head2);
                printf("Lists concatenated.\n");
                break;
            }

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}
