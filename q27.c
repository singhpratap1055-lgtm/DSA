#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection node
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Move pointer of longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    // Traverse both lists together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    struct Node *head1 = NULL, *tail1 = NULL;

    // Create first list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL, *tail2 = NULL;
    struct Node *intersectionNode = NULL;

    // Create second list
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);

        // Check if value exists in first list
        struct Node* temp = head1;
        while (temp != NULL) {
            if (temp->data == value) {
                intersectionNode = temp;
                break;
            }
            temp = temp->next;
        }

        if (intersectionNode != NULL) {
            if (head2 == NULL) {
                head2 = intersectionNode;
            } else {
                tail2->next = intersectionNode;
            }
            break;  // attach and stop
        } else {
            struct Node* newNode = createNode(value);
            if (head2 == NULL) {
                head2 = tail2 = newNode;
            } else {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }
    }

    struct Node* result = findIntersection(head1, head2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}