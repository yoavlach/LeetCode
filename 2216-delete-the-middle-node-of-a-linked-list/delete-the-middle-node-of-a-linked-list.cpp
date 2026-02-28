class Solution {
public:
    ListNode* deleteMiddle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slowPrev = nullptr;
        if (!head->next)
            head = nullptr;
        else
        {
            for (int counter = 0; fast; counter++)
            {
                if (fast)
                    fast = fast->next;
                if (counter % 2 != 0)
                {
                    slowPrev = slow;
                    slow = slow->next;
                }
            }
            slowPrev->next = slow->next;
            delete slow;
        }
        return head;
    }
}; 
