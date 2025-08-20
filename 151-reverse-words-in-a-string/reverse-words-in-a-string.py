import re
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.strip()
        s = re.sub(r' {2,}', ' ', s)
        s = s.split(' ')
        s = s[::-1]
        return ' '.join(s)
            