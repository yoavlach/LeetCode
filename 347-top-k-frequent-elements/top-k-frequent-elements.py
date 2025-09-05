class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        nums_and_appearances = {}
        for i in nums:
            if i in nums_and_appearances:
                nums_and_appearances[i] += 1
            else:
                nums_and_appearances[i] = 1
        largest_k = []
        for i in nums_and_appearances:
            curr_appearance = nums_and_appearances[i]
            to_insert_from = -1
            for j in range(len(largest_k)):
                if to_insert_from == -1 and curr_appearance > nums_and_appearances[largest_k[j]]:
                    to_insert_from = j
            if to_insert_from != -1 or len(largest_k) < k:
                if to_insert_from == -1:
                    largest_k.append(i)
                else:
                    largest_k.insert(to_insert_from, i)
                if len(largest_k) > k:
                    largest_k.pop()
        return largest_k
        