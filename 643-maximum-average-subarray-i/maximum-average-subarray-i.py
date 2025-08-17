class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        i, j = 0, k - 1
        curr_sum, max_sum = None, -2 ** 31
        while j in range(len(nums)):
            if curr_sum is None:
                curr_sum = 0
                for l in range(i, j + 1):
                    curr_sum += nums[l]
            else:
                curr_sum -= nums[i - 1]
                curr_sum += nums[j]
            if curr_sum > max_sum:
                max_sum = curr_sum
            i += 1
            j += 1
        return max_sum / k
            