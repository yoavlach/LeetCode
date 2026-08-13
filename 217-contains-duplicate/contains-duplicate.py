class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums_and_counters = set()
        for i in nums:
            nums_and_counters.add(i)
        return len(nums_and_counters) != len(nums)