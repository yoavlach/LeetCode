class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums_len = len(nums)
        product = 1
        output = [0] * nums_len
        output[0] = 1
        for i in range(1, nums_len + 1):
            output[i - 1] = product
            product *= nums[i - 1]
        product = 1
        for i in range(nums_len, 0, -1):
            output[i - 1] *= product
            product *= nums[i - 1]
        return output
        