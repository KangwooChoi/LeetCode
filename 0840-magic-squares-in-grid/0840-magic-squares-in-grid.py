class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        if row < 3 or col < 3:
            return 0
        
        ans = 0
        for r in range(row-2):
            for c in range(col-2):
                base = sum(grid[r][c:c+3])
                print(base) 
                if base != sum(grid[r+1][c:c+3]):
                    continue
                print("1")
                if base != sum(grid[r+2][c:c+3]):
                    continue
                print("2")
                if base != grid[r][c] + grid[r+1][c] + grid[r+2][c]:
                    continue
                print("3")
                if base != grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1]:
                    continue
                print("4")
                if base != grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2]:
                    continue
                print("5")
                if base != grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2]:
                    continue
                print("6")
                if base != grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2]:
                    continue
                print("7")
                ans +=1
        return ans