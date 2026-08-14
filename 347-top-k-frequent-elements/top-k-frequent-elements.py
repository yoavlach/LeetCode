class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        el_and_appearance = {}

        for i in nums:
            if i in el_and_appearance:
                el_and_appearance[i] += 1
            else:
                el_and_appearance[i] = 1

        return sorted(el_and_appearance, key=el_and_appearance.get, reverse=True)[:k]