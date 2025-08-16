class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zeros_counter = 0
        num_len = len(nums)
        i = 0
        while i in range(num_len):
            if i >= num_len - zeros_counter:
                break
            if nums[i] == 0:
                nums.pop(i)
                zeros_counter += 1
            else:
                i += 1
        nums.extend([0] * zeros_counter)