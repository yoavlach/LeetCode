class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        anagrams = []
        letters_and_appearances = []
        for i in strs:
            curr_letters_and_appearances = {}
            for j in i:
                if j in curr_letters_and_appearances:
                    curr_letters_and_appearances[j] += 1
                else:
                    curr_letters_and_appearances[j] = 0
            found_anagram = False
            for k in range(len(letters_and_appearances)):
                if letters_and_appearances[k] == curr_letters_and_appearances:
                    anagrams[k].append(i)
                    found_anagram = True
            if not found_anagram or not anagrams:
                anagrams.append([i])
                letters_and_appearances.append(curr_letters_and_appearances)
        return anagrams
        