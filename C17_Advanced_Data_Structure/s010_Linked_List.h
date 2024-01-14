#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

/**
 * @brief Create a new node with the given value.
 *
 * @param val The value of the new node.
 * @return ListNode* A pointer to the newly created node.
 */
ListNode* createNode(int val);

/**
 * @brief Insert a new node at the beginning of the list.
 *
 * @param head The head of the list.
 * @param val The value of the new node.
 * @return ListNode* A pointer to the updated head of the list.
 */
ListNode* insertAtHead(ListNode* head, int val);

/**
 * @brief Insert a new node at the end of the list.
 *
 * @param head The head of the list.
 * @param val The value of the new node.
 * @return ListNode* A pointer to the head of the list.
 */
ListNode* insertAtTail(ListNode* head, int val);

/**
 * @brief Delete the node with the given value from the list.
 *
 * @param head The head of the list.
 * @param val The value of the node to be deleted.
 * @return ListNode* A pointer to the head of the list.
 */
ListNode* deleteNode(ListNode* head, int val);

/**
 * @brief Find the node with the given value in the list.
 *
 * @param head The head of the list.
 * @param val The value to search for.
 * @return ListNode* A pointer to the node with the given value, or NULL if not found.
 */
ListNode* findNode(ListNode* head, int val);

/**
 * @brief Update the value of the node with the given value.
 *
 * @param head The head of the list.
 * @param val The value of the node to be updated.
 * @param newVal The new value to be assigned to the node.
 * @return ListNode* A pointer to the head of the list.
 */
ListNode* updateNode(ListNode* head, int val, int newVal);

/**
 * @brief Print the elements of the list.
 *
 * @param head The head of the list.
 */
void printList(ListNode* head);

/**
 * @brief Free the memory allocated for the list.
 *
 * @param head The head of the list.
 */
void freeList(ListNode* head);

/**
 * @brief Build a linked list from an array of integers.
 *
 * @param nums The array of integers.
 * @param n The number of elements in the array.
 * @return ListNode* A pointer to the head of the list.
 */
ListNode* buildList(int* nums, int n);

/**
 * @brief The main function.
 *
 * @return int The exit status of the program.
 */
int test(void);

// Create a new node
ListNode* createNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Insert a new node at the beginning of the list
ListNode* insertAtHead(ListNode* head, int val) {
    ListNode* node = createNode(val);
    node->next = head;
    return node;
}

// Insert a new node at the end of the list
ListNode* insertAtTail(ListNode* head, int val) {
    ListNode* node = createNode(val);
    if (head == NULL) {
        return node;
    }
    ListNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = node;
    return head;
}

// Delete the node with given value
ListNode* deleteNode(ListNode* head, int val) {
    if (head == NULL) {
        return NULL;
    }
    if (head->val == val) {
        ListNode* next = head->next;
        free(head);
        return next;
    }
    ListNode* cur = head;
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            ListNode* next = cur->next->next;
            free(cur->next);
            cur->next = next;
            return head;
        }
        cur = cur->next;
    }
    return head;
}

// Find the node with given value
ListNode* findNode(ListNode* head, int val) {
    ListNode* cur = head;
    while (cur != NULL) {
        if (cur->val == val) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

// Update the value of the node with given value
ListNode* updateNode(ListNode* head, int val, int newVal) {
    ListNode* node = findNode(head, val);
    if (node != NULL) {
        node->val = newVal;
    }
    return head;
}

// Print the list
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

// Free the list
void freeList(ListNode* head) {
    ListNode* cur = head;
    while (cur != NULL) {
        ListNode* next = cur->next;
        free(cur);
        cur = next;
    }
}

// Build a list by array
ListNode* buildList(int* nums, int n) {
    ListNode* head = NULL;
    for (int i = n - 1; i >= 0; i--) {
        head = insertAtHead(head, nums[i]);
    }
    return head;
}

int test(void) {
    ListNode* head = NULL;
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    head = insertAtTail(head, 40);
    head = insertAtTail(head, 50);
    printList(head);
    head = deleteNode(head, 30);
    head = deleteNode(head, 50);
    printList(head);
    head = updateNode(head, 10, 100);
    head = updateNode(head, 40, 400);
    printList(head);
    freeList(head);
    return 0;
}