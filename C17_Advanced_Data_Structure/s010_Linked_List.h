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