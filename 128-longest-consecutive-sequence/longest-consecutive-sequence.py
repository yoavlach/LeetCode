class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        nums.sort()
        num_and_consecutive_counter = {}
        for i in nums:
            if i - 1 in num_and_consecutive_counter:
                counter = num_and_consecutive_counter[i - 1]
                del num_and_consecutive_counter[i - 1]
                num_and_consecutive_counter[i] = counter + 1
            elif i not in num_and_consecutive_counter:
                num_and_consecutive_counter[i] = 1
        return max(num_and_consecutive_counter.values())