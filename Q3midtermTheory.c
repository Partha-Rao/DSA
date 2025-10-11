#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct QueueNode {
    Node *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, Node *treeNode) {
    if (!treeNode) return;
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Node* dequeue(Queue *q) {
    if (q->front == NULL) return NULL;
    QueueNode *temp = q->front;
    Node *treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

Node* createNode(char data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->frequency = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* findNode(Node *root, char c) {
    if (root == NULL) return NULL;
    Queue *q = createQueue();
    enqueue(q, root);
    
    Node *current;
    while (!isEmpty(q)) {
        current = dequeue(q);
        if (current->data == c) {
            while (!isEmpty(q)) dequeue(q);
            free(q);
            return current;
        }
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }
    free(q);
    return NULL; 
}

Node* buildBinaryTree(const char* inputString) {
    if (inputString == NULL || inputString[0] == '\0') return NULL;

    Node *root = NULL;
    Queue *insertionQ = createQueue();
    
    int len = strlen(inputString);
    for (int i = 0; i < len; i++) {
        char c = inputString[i];
        
       
        Node *existingNode = findNode(root, c);

        if (existingNode != NULL) {
            existingNode->frequency++;
        } else {
            Node *newNode = createNode(c);

            if (root == NULL) {
                
                root = newNode;
                enqueue(insertionQ, root); 
            } else {
                Node *parent = insertionQ->front->treeNode; 

                if (parent->left == NULL) {
                    parent->left = newNode;
                } else if (parent->right == NULL) {
                    parent->right = newNode;
                    
                    dequeue(insertionQ); 
                }
                enqueue(insertionQ, newNode);
            }
        }
    }
    while (!isEmpty(insertionQ)) dequeue(insertionQ);
    free(insertionQ);
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    Queue *outputQ = createQueue();
    enqueue(outputQ, root);
    
    printf("Level order traversal output:\n");
    printf("Expected format: ");

    int first = 1; 

    while (!isEmpty(outputQ)) {
        Node *current = dequeue(outputQ);
        
        if (!first) {
            printf(", ");
        }
        printf("(%c,%d)", current->data, current->frequency);
        first = 0;
        
        if (current->left != NULL) enqueue(outputQ, current->left);
        if (current->right != NULL) enqueue(outputQ, current->right);
    }
    printf("\n");
    
    while (!isEmpty(outputQ)) dequeue(outputQ);
    free(outputQ);
}

int main() {
    const char *inputString = "programming";
    
    printf("Input: \"%s\"\n", inputString);
    
    Node *root = buildBinaryTree(inputString);
    
    levelOrderTraversal(root);
    
    
    return 0;
}