class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        ans = 2 ** (len(grid[0])-1) * len(grid)
        for row in grid:
            if row[0] == 0:
                for i in range(len(row)):
                    if row[i] == 0:
                        row[i] = 1
                    else:
                        row[i] = 0
        for i in range(1, len(grid[0])):
            cnt = 0
            for j in range(len(grid)):
                cnt += grid[j][i]
            if 2*cnt >= len(grid):
                ans += cnt * 2 ** (len(grid[0])-1-i)
            else:
                ans += (len(grid)-cnt) * 2 ** (len(grid[0])-1-i)
        return ans