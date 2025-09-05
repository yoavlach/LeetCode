class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(9):
            seen_nums = set()
            for j in board:
                if j[i] != '.':
                    if j[i] in seen_nums:
                        return False
                    seen_nums.add(j[i])
        for i in board:
            seen_nums = set()
            for j in i:
                if j != '.':
                    if j in seen_nums:
                        return False
                    seen_nums.add(j)
        all_nums_in_squares = [set() for i in range(9)]
        curr_add = 0
        for i in range(len(board)):
            if i % 3 == 0:
                curr_add = i
            for j in range(len(board[i])):
                if board[i][j] != '.':
                    if board[i][j] in all_nums_in_squares[curr_add + j // 3]:
                        return False
                    all_nums_in_squares[curr_add + j // 3].add(board[i][j])
        return True
        