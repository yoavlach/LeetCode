# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if head and head.next:
            curr, prev, sec_prev = head.next, head, None
            while curr:
                prev.next = sec_prev
                sec_prev = prev
                prev = curr
                if not curr.next:
                    head = curr
                curr = curr.next
            prev.next = sec_prev
        return head
        