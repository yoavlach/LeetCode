# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def getDecimalValue(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: int
        """
        if head:
            curr = head
            converted_to_decimal = 0
            while curr:
                converted_to_decimal *= 2
                converted_to_decimal += curr.val
                curr = curr.next
            return converted_to_decimal
        