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

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void reverseBetween(struct Node** head, int m, int n) {
    if (m == n) return;

    struct Node temp;
    temp.next = *head;
    struct Node* prev = &temp;

    for (int i = 1; i < m; i++)
        prev = prev->next;

    struct Node* curr = prev->next;
    struct Node* nextNode = NULL;

    for (int i = 0; i < n - m; i++) {
        nextNode = curr->next;
        curr->next = nextNode->next;
        nextNode->next = prev->next;
        prev->next = nextNode;
    }

    *head = temp.next;
}

int main() {
    struct Node* head = createNode(101);
    head->next = createNode(102);
    head->next->next = createNode(103);
    head->next->next->next = createNode(104);
    head->next->next->next->next = createNode(105);
    head->next->next->next->next->next = createNode(106);
    head->next->next->next->next->next->next = createNode(107);

    printf("Playlist (songIDs):\n");
    printList(head);

    reverseBetween(&head, 2, 5);

    printf("\nModified Playlist:\n");
    printList(head);

    return 0;
}

