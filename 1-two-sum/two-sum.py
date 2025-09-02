class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_and_remaining = {}
        for i in range(len(nums)):
            if target - nums[i] in num_and_remaining:
                return [num_and_remaining[target - nums[i]], i]
            else:
                num_and_remaining[nums[i]] = i
        return []
        