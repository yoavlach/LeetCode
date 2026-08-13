class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        chars_and_appearances = {}
        
        for i in s:
            if i in chars_and_appearances:
                chars_and_appearances[i] += 1
            else:
                chars_and_appearances[i] = 1
        
        for i in t:
            if i in chars_and_appearances:
                chars_and_appearances[i] -= 1
                if chars_and_appearances[i] < 0:
                    return False
            else:
                return False
        
        for i in chars_and_appearances.values():
            if i != 0:
                return False
        return True