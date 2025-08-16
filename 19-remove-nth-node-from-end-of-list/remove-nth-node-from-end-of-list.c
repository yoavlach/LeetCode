/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i = 0;
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* nPtr = head;
    for(i = 0; curr; i++)
    {
        if(i >= n)
        {
            prev = nPtr;
            nPtr = nPtr->next;
        }
        curr = curr->next;
    }
    if(!nPtr || !prev) head = head->next;
    else if(!nPtr->next) prev->next = NULL;
    else prev->next = nPtr->next;
    free(nPtr);
    return head;
}