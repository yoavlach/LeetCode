class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        if str1 == str2:
            return str1
        gcds = [check(str1, str2), check(str2, str1)]
        return max(gcds, key=len)


def check(str1, str2):
    gcd = ""
    for i in range(len(str1)):
        for j in range(i + 1, len(str1)):
            check_str = str1[i:j]
            str2_len, check_str_len = len(str2), len(check_str)
            if len(str1) % (j - i) == 0 and check_str * int(len(str1) / (j - i)) == str1 and check_str_len > len(gcd) and check_str * int(str2_len / check_str_len) == str2:
                gcd = check_str
                break
    return gcd
        