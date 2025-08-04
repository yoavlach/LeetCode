class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        string = str(x)
        if x < 0:
            string = string[1:]
            string += "-"
        reversed = int(string[::-1])
        if reversed > (2 ** 31 - 1) or reversed < -2 ** 31:
            return 0
        return int(string[::-1])
        