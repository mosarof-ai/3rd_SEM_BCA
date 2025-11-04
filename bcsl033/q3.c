#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        if (head->next != NULL) printf("-> ");
        head = head->next;
    }
    printf("\n");
}

void countEvenOdd(struct Node* head) {
    int even = 0, odd = 0;
    struct Node* temp = head;
    printf("\nEven numbers: ");
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            printf("%d ", temp->data);
            even++;
        }
        temp = temp->next;
    }
    temp = head;
    printf("\nOdd numbers: ");
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            printf("%d ", temp->data);
            odd++;
        }
        temp = temp->next;
    }
    printf("\nTotal Even: %d, Odd: %d\n", even, odd);
}

void sortList(struct Node* head) {
    if (head == NULL || head->next == NULL) return;
    int swapped;
    struct Node *ptr1, *ptr2 = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}

int main() {
    struct Node* head = NULL;
    int n, value, choice;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if (n <= 0) return 1;
    
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }
    
    do {
        printf("\n1.Count Even/Odd\n2.Sort\n3.Display\n4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: countEvenOdd(head); break;
            case 2: sortList(head); displayList(head); break;
            case 3: displayList(head); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
