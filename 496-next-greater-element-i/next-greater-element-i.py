class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        next_greatest = []
        nums1len, nums2len = len(nums1), len(nums2)
        for i in range(nums1len):
            found_equal = False
            for j in range(nums2len):
                if found_equal and nums2[j] > nums1[i]:
                    next_greatest.append(nums2[j])
                    break
                elif nums1[i] == nums2[j]:
                    found_equal = True
                if j == nums2len - 1:
                    next_greatest.append(-1)
        return next_greatest
        