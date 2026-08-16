class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # [-1,1,0,-3,3] -> [0,0,9,0,0]

        overall_mul = 1
        zero_counter = 0
        for i in nums:
            if i == 0:
                zero_counter += 1
            else:
                overall_mul *= i

        if zero_counter == len(nums):
            overall_mul = 0

        res = []
        for i in range(len(nums)):
            if nums[i] == 0:
                if zero_counter > 1:
                    res.append(0)
                else:
                    res.append(overall_mul)
            else:
                if zero_counter > 0:
                    res.append(0)
                else:
                    res.append(overall_mul / nums[i])
        return res
