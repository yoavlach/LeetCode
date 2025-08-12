ROMAN_NUMBERS = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
}

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        converted, i = 0, 0
        while i in range(len(s)):
            if i + 1 < len(s) and ((s[i] == 'I' and s[i + 1] in ['X', 'V']) or (s[i] == 'X' and s[i + 1] in ['L', 'C']) or (s[i] == 'C' and s[i + 1] in ['D', 'M'])):
                converted += ROMAN_NUMBERS[s[i + 1]] - ROMAN_NUMBERS[s[i]]
                i += 1
            else:
                converted += ROMAN_NUMBERS[s[i]]
            i += 1
        return converted
        