class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels_in_s = []
        new_str = ""
        for i in s:
            if i.lower() in "aeiou":
                vowels_in_s.append(i)
        curr_vowel = 0
        vowels_in_s.reverse()
        for i in s:
            if i.lower() in "aeiou":
                new_str += vowels_in_s[curr_vowel]
                curr_vowel += 1
            else:
                new_str += i
        return new_str