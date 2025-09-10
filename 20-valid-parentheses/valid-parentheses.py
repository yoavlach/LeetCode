class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        close_to_open = {
            ")": "(",
            "}": "{",
            "]": "["
        }
        stack = []
        for i in s:
            if i in close_to_open.values():
                stack.append(i)
            else:
                if len(stack) == 0 or stack[-1] != close_to_open[i]:
                    return False
                stack.pop()
        return len(stack) == 0