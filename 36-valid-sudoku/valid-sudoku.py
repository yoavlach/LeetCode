class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        for i in range(9):
            curr_h = set()
            curr_v = set()
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in curr_h:
                        return False
                    curr_h.add(board[i][j])
                if board[j][i] != '.':
                    if board[j][i] in curr_v:
                        return False
                    curr_v.add(board[j][i])

        for start_x in range(0, 9, 3):
            for start_y in range(0, 9, 3):
                curr_g = set()
                for y in range(start_y, start_y + 3):
                    for x in range(start_x, start_x + 3):
                        if board[x][y] != '.':
                            if board[x][y] in curr_g:
                                return False
                            curr_g.add(board[x][y])
        return True