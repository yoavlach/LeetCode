class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        curr_str = ""
        longest_prefix = ""
        for i in range(len(strs[0])):
            curr_str += strs[0][i]
            is_prefix = True
            for j in strs[0:]:
                if not j.startswith(curr_str):
                    is_prefix = False
                    break
            if is_prefix and len(longest_prefix) < len(curr_str):
                longest_prefix = curr_str
        return longest_prefix
        