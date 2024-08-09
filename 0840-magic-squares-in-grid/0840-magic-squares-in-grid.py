class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        ans = 0
        m = len(grid)
        n = len(grid[0])
        for row in range(m - 2):
            for col in range(n - 2):
                if self._isMagicSquare(grid, row, col):
                    ans += 1
        return ans

    def _isMagicSquare(self, grid, row, col):
        seen = [False] * 10
        for i in range(3):
            for j in range(3):
                num = grid[row + i][col + j]
                if num < 1 or num > 9:
                    return False
                if seen[num]:
                    return False
                seen[num] = True

        # Check if diagonal sums are the same
        diagonal1 = (
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]
        )
        diagonal2 = (
            grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2]
        )

        if diagonal1 != diagonal2:
            return False

        # Check if all row sums are the same as the diagonal sums
        row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2]
        row2 = (
            grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2]
        )
        row3 = (
            grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2]
        )

        if not (row1 == diagonal1 and row2 == diagonal1 and row3 == diagonal1):
            return False

        # Check if all column sums are the same as the diagonal sums
        col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col]
        col2 = (
            grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1]
        )
        col3 = (
            grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2]
        )

        if not (col1 == diagonal1 and col2 == diagonal1 and col3 == diagonal1):
            return False

        return True
#class Solution:
#    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
#        row = len(grid)
#        col = len(grid[0])
#        if row < 3 or col < 3:
#            return 0
#        
#        ans = 0
#        for r in range(row-2):
#            for c in range(col-2):
#                base = sum(grid[r][c:c+3])
#                print(base) 
#                if base != sum(grid[r+1][c:c+3]):
#                    continue
#                print("1")
#                if base != sum(grid[r+2][c:c+3]):
#                    continue
#                print("2")
#                if base != grid[r][c] + grid[r+1][c] + grid[r+2][c]:
#                    continue
#                print("3")
#                if base != grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1]:
#                    continue
#                print("4")
#                if base != grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2]:
#                    continue
#                print("5")
#                if base != grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2]:
#                    continue
#                print("6")
#                if base != grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2]:
#                    continue
#                print("7")
#                ans +=1
#        return ans