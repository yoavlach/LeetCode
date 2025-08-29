# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if head:
            curr, runner, prev_runner = head, head.next, head
            while curr:
                prev_runner = curr
                runner = curr.next
                while runner:
                    if runner.val == curr.val:
                        prev_runner.next = runner.next
                    else:
                        prev_runner = runner
                    runner = runner.next
                curr = curr.next
        return head
        