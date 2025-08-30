class Solution(object):
    def minimumPairRemoval(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counter = 0
        while nums != sorted(nums):
            smallest_sum = 2 ** 31 - 1
            smallest_pair = None
            for i in range(1, len(nums)):
                if nums[i] + nums[i - 1] < smallest_sum:
                    smallest_pair = [i - 1, i]
                    smallest_sum = nums[i] + nums[i - 1]
            del nums[smallest_pair[1]]
            del nums[smallest_pair[0]]
            nums.insert(smallest_pair[0], smallest_sum)
            counter += 1
        return counter
        