class Solution(object):
    def calPoints(self, operations):
        """
        :type operations: List[str]
        :rtype: int
        """
        stack = []
        for i in operations:
            if i.isdigit() or (i[1:].isdigit() and i[0] == "-"):
                stack.append(int(i))
            elif i == '+':
                first = stack[-1]
                stack.pop()
                second = stack[-1]
                stack.append(first)
                stack.append(first + second)
            elif i == 'D':
                stack.append(stack[-1] * 2)
            elif i == 'C':
                stack.pop()
        sum = 0
        for i in stack:
            sum += i
        return sum
        