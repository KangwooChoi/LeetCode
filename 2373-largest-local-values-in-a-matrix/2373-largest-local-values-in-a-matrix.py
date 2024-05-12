class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        def findMax(x, y):
            dx = [-1, -1, 0, 1, 1, 1, 0, -1] 
            dy = [0, 1, 1, 1, 0, -1, -1, -1] 
            ret = grid[x][y]
            for k in range(8):
                if 0 <= x+dx[k] < n and 0 <= y+dy[k] < n:
                    ret = max(ret, grid[x+dx[k]][y+dy[k]])
            return ret
        n = len(grid)
        ans = [[0] * (n-2) for _ in range(n-2)]
        for i in range(1, n-1):
            for j in range(1, n-1):
                ans[i-1][j-1] = findMax(i, j)
        return ans