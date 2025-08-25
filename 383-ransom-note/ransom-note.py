class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransom_letters_and_appearances = {}
        magazine_letters_and_appearances = {}
        for i in ransomNote:
            if i in ransom_letters_and_appearances.keys():
                ransom_letters_and_appearances[i] += 1
            else:
                ransom_letters_and_appearances[i] = 0
        for i in magazine:
            if i in magazine_letters_and_appearances.keys():
                magazine_letters_and_appearances[i] += 1
            else:
                magazine_letters_and_appearances[i] = 0
        for i in ransom_letters_and_appearances:
            if i not in magazine_letters_and_appearances.keys() or ransom_letters_and_appearances[i] > magazine_letters_and_appearances[i]:
                return False
        return True