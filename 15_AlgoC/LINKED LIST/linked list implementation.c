#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertNode(Node** head, int data);
Node* findNode(Node* head, int data);
void updateNode(Node* node, int newData);
void deleteNode(Node** head, int data);
void traverseList(Node* head);

int main() {
    Node* head = NULL;

    // Insert nodes
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);

    // Traverse the list
    traverseList(head);

    // Find and update a node
    Node* nodeToUpdate = findNode(head, 2);
    if (nodeToUpdate) {
        updateNode(nodeToUpdate, 4);
    }

    // Traverse the list after update
    traverseList(head);

    // Delete a node
    deleteNode(&head, 1);

    // Traverse the list after deletion
    traverseList(head);

    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) { // 在这里，为什么要使用 Node** head 而不是 Node* head,
    Node* newNode = createNode(data);    // 因为，最后需要修改 head 头指针的值，因此传递的不是头
    newNode->next = *head;               // 指针而是头指针的地址。
    *head = newNode;
}

Node* findNode(Node* head, int data) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->data == data) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

void updateNode(Node* node, int newData) {
    if (node != NULL) {
        node->data = newData;
    }
}

/* 
过程思路：
    创建2个指针，一个指向头节点，一个指向NULL；    

    while (currentNode非空) {
        检查：currentNode 合法性
        合法：两个指针前进一位
        不合法：将后指针指向它前面的前面的位置，return，注意要考虑到特殊情况（要改变头指针的情况）
    } */
void deleteNode(Node** head, int data) {
    Node* currentNode = *head;
    Node* previousNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->data == data) {
            if (previousNode == NULL) {
                *head = currentNode->next;
            } else {
                previousNode->next = currentNode->next;
            }
            free(currentNode);
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}

void traverseList(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}