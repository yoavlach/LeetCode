class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode* curr = head;
        ListNode* currOdd = nullptr;
        ListNode* currEven = nullptr;
        ListNode* secondHead = nullptr;
        if (head && head->next)
        {
            secondHead = head->next;
            for (int i = 0; curr; i++)
            {
                if (i % 2 != 0)
                {
                    if (currEven)
                        currEven->next = curr;
                    currEven = curr;
                }
                else
                {
                    if (currOdd)
                        currOdd->next = curr;
                    currOdd = curr;
                }
                curr = curr->next;
            }
            currOdd->next = secondHead;
            currEven->next = nullptr;
        }
        return head;
    }
};
