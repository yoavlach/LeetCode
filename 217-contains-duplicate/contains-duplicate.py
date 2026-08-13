class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums_and_counters = set(nums)
        return len(nums_and_counters) != len(nums)