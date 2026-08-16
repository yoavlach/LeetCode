class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        overall_mul = 1
        zero_counter = 0
        nums_len = len(nums)

        for i in nums:
            if i == 0:
                zero_counter += 1
            else:
                overall_mul *= i

        if zero_counter == nums_len:
            overall_mul = 0

        res = [0] * nums_len
        for i in range(nums_len):
            if nums[i] == 0:
                if zero_counter > 1:
                    res[i] = 0
                else:
                    res[i] = overall_mul
            else:
                if zero_counter > 0:
                    res[i] = 0
                else:
                    res[i] = overall_mul / nums[i]
        return res

