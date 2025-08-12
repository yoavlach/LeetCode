class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        largest_common = ""
        for i in range(len(strs[0]) + 1):
            curr = strs[0][:i]
            is_in_all = True
            for j in strs:
                if j[:len(curr)] != curr:
                    is_in_all = False
                    break
            if is_in_all and len(curr) > len(largest_common):
                largest_common = curr
        return largest_common
            