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
class Solution 
{
public:
    int pairSum(ListNode* head)
    {
        vector<int> sums;
        ListNode* slow = head;
        ListNode* fast = head;
        int max = 0, i = 0, j = 0;
        for (i = 0; fast; i++)
        {
            fast = fast->next;
            if (i % 2 != 0)
            {
                sums.push_back(slow->val);
                slow = slow->next;
            }
        }
        if (i % 2 != 0)
            slow = slow->next;
        for (j = 0; slow; j++)
        {
            sums[i / 2 - j - 1] += slow->val;
            if (sums[i / 2 - j - 1] > max)
                max = sums[i / 2 - j - 1];
            slow = slow->next;
        }
        return max;
    }
};
