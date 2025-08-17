class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        i, j = 0, k - 1
        curr_avg, max_avg = None, -2 ** 31
        while j in range(len(nums)):
            if curr_avg is None:
                curr_avg = 0
                for l in range(i, j + 1):
                    curr_avg += nums[l]
                curr_avg /= k
            else:
                curr_avg *= k
                curr_avg -= nums[i - 1]
                curr_avg += nums[j]
                curr_avg /= k
            if curr_avg > max_avg:
                max_avg = curr_avg
            i += 1
            j += 1
        return max_avg
            