#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node *ptr = head;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

void insert_front(struct Node **head, int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->link = *head;
    *head = newNode;
}

void insert_end(struct Node **head, int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->link = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *ptr = *head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newNode;
}

void insert_after(struct Node *head, int key, int x) {
    if (head == NULL) {
        printf("Search failed. Insertion not possible\n");
        return;
    }
    struct Node *ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("Search failed. Insertion not possible\n");
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->link = ptr->link;
    ptr->link = newNode;
}

void delete_front(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->link;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void delete_end(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible\n");
        return;
    }
    struct Node *ptr = *head;
    struct Node *prev = NULL;
    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->link = NULL;
    }
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
}

void delete_specific(struct Node **head, int key) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible\n");
        return;
    }
    struct Node *ptr = *head, *prev = NULL;
    while (ptr != NULL && ptr->data != key) {
        prev = ptr;
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("Key not found. Deletion not possible\n");
        return;
    }
    if (prev == NULL) {
        *head = (*head)->link;
    } else {
        prev->link = ptr->link;
    }
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
}

void search(struct Node *head, int key) {
    struct Node *ptr = head;
    int pos = 1;
    while (ptr != NULL) {
        if (ptr->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        ptr = ptr->link;
        pos++;
    }
    printf("Element %d not found in the list\n", key);
}

struct Node* merge(struct Node *h1, struct Node *h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;
    struct Node *ptr = h1;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = h2;
    return h1;
}

int main() {
    int choice, listChoice, x, key;
    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete Front\n");
        printf("5. Delete End\n");
        printf("6. Delete Specific Node\n");
        printf("7. Display\n");
        printf("8. Merge List2 into List1\n");
        printf("9. Search for Element\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 10) break;

        if (choice >= 1 && choice <= 7 || choice == 9) {
            printf("Which list? (1 or 2): ");
            scanf("%d", &listChoice);
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                if (listChoice == 1) insert_front(&head1, x);
                else insert_front(&head2, x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                if (listChoice == 1) insert_end(&head1, x);
                else insert_end(&head2, x);
                break;
            case 3:
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &x);
                if (listChoice == 1) insert_after(head1, key, x);
                else insert_after(head2, key, x);
                break;
            case 4:
                if (listChoice == 1) delete_front(&head1);
                else delete_front(&head2);
                break;
            case 5:
                if (listChoice == 1) delete_end(&head1);
                else delete_end(&head2);
                break;
            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                if (listChoice == 1) delete_specific(&head1, key);
                else delete_specific(&head2, key);
                break;
            case 7:
                if (listChoice == 1) display(head1);
                else display(head2);
                break;
            case 8:
                head1 = merge(head1, head2);
                head2 = NULL;
                printf("Lists merged. Now List1: ");
                display(head1);
                break;
            case 9:
                printf("Enter element to search: ");
                scanf("%d", &key);
                if (listChoice == 1) search(head1, key);
                else search(head2, key);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}