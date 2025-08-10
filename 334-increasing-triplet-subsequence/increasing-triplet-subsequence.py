INDEX_INDEX = 0
VALUE_INDEX = 1

class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        smallest, second_smallest = 2 ** 31 - 1, 2 ** 31 - 1
        for i in nums:
            if i <= smallest:
                smallest = i
            elif i <= second_smallest:
                second_smallest = i
            else:
                return True
        return False
        