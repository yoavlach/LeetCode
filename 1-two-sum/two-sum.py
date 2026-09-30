class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        nums_and_indexes = {}
        #2: 0
        #7: 1
        for i in range(len(nums)):
            if target - nums[i] in nums_and_indexes:
                return [i, nums_and_indexes[target - nums[i]]]
            nums_and_indexes[nums[i]] = i
        