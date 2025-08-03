# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        curr_l1, curr_l2 = l1, l2
        i = 1
        sum = 0
        while curr_l1:
            sum += curr_l1.val * i
            curr_l1 = curr_l1.next
            i *= 10
        i = 1
        while curr_l2:
            sum += curr_l2.val * i
            curr_l2 = curr_l2.next
            i *= 10
        str_sum = str(sum)
        res = []
        for i in str_sum:
            res.append(int(i))
        head = ListNode(res[-1])
        current = head
        for num in res[-2::-1]:
            current.next = ListNode(num)
            current = current.next
        return head
        