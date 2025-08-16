class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        digits_that_were_in_nums = []
        i = 0
        while i in range(len(nums)):
            if nums[i] in digits_that_were_in_nums:
                nums.pop(i)
            else:
                digits_that_were_in_nums.append(nums[i])
                i += 1
        return len(nums)
        