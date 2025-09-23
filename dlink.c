#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void display() {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insert_front(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insert_end(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
}

void insert_after(int key, int x) {
    struct Node *ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Key not found. Insertion not possible\n");
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = ptr->next;
    newNode->prev = ptr;
    if (ptr->next != NULL) {
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;
}

void delete_front() {
    if (head == NULL) {
        printf("List is empty. Deletion not possible\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty. Deletion not possible\n");
        return;
    }
    struct Node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    if (ptr->prev != NULL) {
        ptr->prev->next = NULL;
    } else {
        head = NULL;
    }
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
}

void delete_specific(int key) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible\n");
        return;
    }
    struct Node *ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Key not found. Deletion not possible\n");
        return;
    }
    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    } else {
        head = ptr->next;
    }
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
}

void search(int key) {
    struct Node *ptr = head;
    int pos = 1;
    while (ptr != NULL) {
        if (ptr->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("Element %d not found in the list\n", key);
}

void merge_list() {
    struct Node *tempHead = NULL, *ptr, *newNode;
    int n, val;
    printf("Enter number of nodes in second list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (tempHead == NULL) {
            newNode->prev = NULL;
            tempHead = newNode;
        } else {
            ptr = tempHead;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->prev = ptr;
        }
    }
    if (head == NULL) {
        head = tempHead;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = tempHead;
        if (tempHead != NULL) {
            tempHead->prev = ptr;
        }
    }
    printf("Lists merged successfully\n");
}

int main() {
    int choice, val, key;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete Front\n");
        printf("5. Delete End\n");
        printf("6. Delete Specific\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Merge Another List\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_front(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 3:
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &val);
                insert_after(key, val);
                break;
            case 4:
                delete_front();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                printf("Enter key: ");
                scanf("%d", &key);
                delete_specific(key);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 8:
                display();
                break;
            case 9:
                merge_list();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}#FF0A00