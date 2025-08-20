class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        converted_str = ""
        for i in s:
            if i.isalpha() or i.isdigit():
                converted_str += i.lower()
        return converted_str == converted_str[::-1]
        