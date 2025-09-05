class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        letters_and_appearances = {}
        for i in s:
            if i in letters_and_appearances:
                letters_and_appearances[i] += 1
            else:
                letters_and_appearances[i] = 1
        for i in t:
            if i in letters_and_appearances and letters_and_appearances[i] > 0:
                letters_and_appearances[i] -= 1
            else:
                return False
        return max(letters_and_appearances.values()) == 0

        