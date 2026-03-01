/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
                    {
                        currEven->next = curr;
                    }
                    currEven = curr;
                }
                else
                {
                    if (currOdd)
                    {
                        currOdd->next = curr;
                    }
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

