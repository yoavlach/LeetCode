class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_and_appearances = {}
        for i in nums:
            if i in nums_and_appearances.keys():
                nums_and_appearances[i] += 1
            else:
                nums_and_appearances[i] = 1
        potential_majority = max(nums_and_appearances, key=nums_and_appearances.get)
        if nums_and_appearances[potential_majority] * 2 > len(nums):
            return potential_majority
        