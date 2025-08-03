class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        substring = ""
        lengths = []
        if len(s) == 1:
            return 1
        for i in range(len(s)):
            substring += s[i]
            for j in range(i + 1, len(s)):
                substring += s[j]
                if s[j] in substring[:-1]:
                    lengths.append(len(substring) - 1)
                    break
                if j + 1 == len(s):
                    lengths.append(len(substring))
                    break
            substring = ""
        if not lengths:
            return 0
        return max(lengths)