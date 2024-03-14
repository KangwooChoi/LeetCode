class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        def dfs(x, y):
            ret = True
            if x <= 0 or x >= n-1 or y <= 0 or y >= m-1:
                return False
            else:
                grid[x][y] = 1    
                if grid[x-1][y] == 0:
                   if dfs(x-1, y) == False:
                       ret = False
                if grid[x+1][y] == 0:
                    if dfs(x+1, y) == False:
                        ret = False 
                if grid[x][y-1] == 0:
                    if dfs(x, y-1) == False:
                        ret = False
                if grid[x][y+1] == 0:
                    if dfs(x, y+1) == False:
                        ret = False
                return ret

        n = len(grid)
        m = len(grid[0])
        ans = 0
        for i in range(1, n-1):
            for j in range(1, m-1):
                if grid[i][j] == 0:
                    grid[i][j] = 1
                    if dfs(i, j) == True:
                        ans += 1
        return ans