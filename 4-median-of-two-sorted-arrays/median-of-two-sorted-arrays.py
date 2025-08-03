class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums.sort()
        len_nums = len(nums)
        if len_nums % 2 != 0:
            return nums[len_nums // 2]
        mid1, mid2 = nums[len_nums // 2], nums[len_nums // 2 - 1]
        return (mid1 + mid2) / 2
        