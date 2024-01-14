#include "s010_Linked_List.h"
#include <stdio.h>

ListNode* invertList(ListNode* head) {
    if (head->next == NULL) {
        return head;
    }
    ListNode* tail = invertList(head->next);
    head->next->next = head;
    head->next = NULL;
    return tail;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* head = buildList(arr, sizeof(arr) / sizeof(arr[0]));
    printList(head);
    head = invertList(head);
    printList(head);
}





