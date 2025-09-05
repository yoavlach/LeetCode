class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        product = 1
        output = [0] * len(nums)
        output[0] = 1
        for i in range(1, len(nums) + 1):
            output[i - 1] = product
            product *= nums[i - 1]
        product = 1
        for i in range(len(nums), 0, -1):
            output[i - 1] *= product
            product *= nums[i - 1]
        return output
        