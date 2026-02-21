#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    
    // Read number of nodes
    scanf("%d", &n);
    
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    
    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        
        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;  // first node
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    // Traverse and print linked list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    return 0;
}