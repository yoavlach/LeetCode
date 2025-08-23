class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        p = sorted(p)
        i, j = 0, len(p)
        start_indices = []
        while j <= len(s):
            curr_substr = sorted(s[i: j])
            if p == curr_substr:
                start_indices.append(i)
            j += 1
            i += 1
        return start_indices
        