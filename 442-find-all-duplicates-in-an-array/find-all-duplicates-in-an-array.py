class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums_and_appearances = {}
        duplicates = []
        for i in nums:
            if i in nums_and_appearances:
                nums_and_appearances[i] += 1
            else:
                nums_and_appearances[i] = 1
        for i in nums_and_appearances:
            if nums_and_appearances[i] > 1:
                duplicates.append(i)
        return duplicates