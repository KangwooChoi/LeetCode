class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        ans = 0
        n = len(grid)
        for i in range(n):
            row = grid[i]
            for j in range(n):
                flag = True
                for k in range(n):
                    if row[k] != grid[k][j]:
                        flag = False
                        break
                if flag == True:
                    ans += 1
        return ans