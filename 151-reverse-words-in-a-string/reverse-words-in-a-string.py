class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.split(' ')
        no_trailing = []
        for i in s:
            if i != '':
                no_trailing.append(i)
        no_trailing.reverse()
        return ' '.join(no_trailing)
            