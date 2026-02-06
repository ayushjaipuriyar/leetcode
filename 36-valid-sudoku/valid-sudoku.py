class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = defaultdict(list)
        rows = defaultdict(list)
        squares = defaultdict(list)
        for r in range(9):
            for c in range(9):
                x = board[r][c]
                currr = rows[r]
                currc = cols[c]
                if x == ".":
                    continue
                if ( x in currr  or x in currc or x in squares[r//3,c//3]):
                    return False
                currc.append(x)
                currr.append(x)
                squares[(r//3,c//3)].append(x)
        return True