class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """

        all_anagrams = {}
        curr_chars_and_appearances = {}

        for i in strs:
            for j in i:
                if j in curr_chars_and_appearances:
                    curr_chars_and_appearances[j] += 1
                else:
                    curr_chars_and_appearances[j] = 1

            key_l = tuple(sorted(curr_chars_and_appearances.items()))
            if key_l in all_anagrams:
                all_anagrams[key_l].append(i)
            else:
                all_anagrams[key_l] = [i]

            curr_chars_and_appearances = {}

        anagram_list = []
        for i in all_anagrams.values():
            anagram_list.append(i)

        return anagram_list