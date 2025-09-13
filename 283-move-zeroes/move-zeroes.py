class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0
        nums_len = len(nums)
        while i < nums_len:
            curr_num = nums[i]
            if curr_num == 0:
                del nums[i]
                nums.append(0)
                nums_len -= 1
            else:
                i += 1