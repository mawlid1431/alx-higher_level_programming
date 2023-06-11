#include <stdio.h>
#include <stdlib.h>

/* Structure for a singly-linked list node */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function to check if a linked list is a palindrome */
int isPalindrome(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    Node* temp = NULL;

    /* Find the middle of the list and reverse the first half */
    while (fast && fast->next) {
        fast = fast->next->next;

        /* Reverse the first half of the list */
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    /* Handle odd length lists */
    if (fast)
        slow = slow->next;

    /* Compare the reversed first half with the second half */
    while (slow) {
        if (slow->data != prev->data)
            return 0;
        slow = slow->next;
        prev = prev->next;
    }

    return 1; /* The list is a palindrome */
}

/* Function to create a new linked list node */
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* Function to free the memory allocated for the linked list */
void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* Test case */
int main() {
    /* Create a sample linked list */
    Node* head = newNode(1);
    head->next = newNode(17);
    head->next->next = newNode(972);
    head->next->next->next = newNode(50);
    head->next->next->next->next = newNode(98);
    head->next->next->next->next->next = newNode(98);
    head->next->next->next->next->next->next = newNode(50);
    head->next->next->next->next->next->next->next = newNode(972);
    head->next->next->next->next->next->next->next->next = newNode(17);
    head->next->next->next->next->next->next->next->next->next = newNode(1);

    /* Check if the linked list is a palindrome */
    int result = isPalindrome(head);

    /* Print the result */
    if (result)
        printf("Linked list is a palindrome\n");
    else
        printf("Linked list is not a palindrome\n");

    /* Free the memory */
    freeList(head);

    return 0;
}
