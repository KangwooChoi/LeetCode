class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        DIRECTIONS = [0, 1, 0, -1, 0]
        rows = len(grid)
        cols = len(grid[0])
        max_gold = 0

        def dfs_backtrack(grid, rows, cols, row, col):
            # Base case: this cell is not in the matrix or has no gold
            if row < 0 or col < 0 or row == rows or col == cols or \
                    grid[row][col] == 0:
                return 0
            max_gold = 0

            # Mark the cell as visited and save the value
            original_val = grid[row][col]
            grid[row][col] = 0

            # Backtrack in each of the four directions
            for direction in range(4):
                max_gold = max(max_gold,
                               dfs_backtrack(grid, rows, cols, 
                                             DIRECTIONS[direction] + row,
                                             DIRECTIONS[direction + 1] + col))

            # Set the cell back to its original value
            grid[row][col] = original_val
            return max_gold + original_val

        # Search for the path with the maximum gold starting from each cell
        for row in range(rows):
            for col in range(cols):
                max_gold = max(max_gold, dfs_backtrack(grid, rows, cols, row, 
                                                       col))
        return max_gold
#class Solution:
#    def getMaximumGold(self, grid: List[List[int]]) -> int:
#        from collections import deque
#        ans = 0
#        m, n = len(grid), len(grid[0])
#        visited_base = [[False] * len(grid[0]) for _ in range(len(grid))]
#        starts = []
#        for i in range(m):
#            for j in range(n):
#                if grid[i][j] == 0:
#                    visited_base[i][j] = True
#                else:
#                    starts.append([i,j])
#
#        def dfs(node, gold, visited_base):
#            dx = [0, 0, -1, 1]
#            dy = [-1, 1, 0, 0]
#            x, y = node
#            gold += grid[x][y]
#            visited = copy.deepcopy(visited_base)
#            visited[x][y] = True
#            golds = [gold]
#            for i in range(4):
#                if 0 <= (x+dx[i]) < m and 0 <= (y+dy[i]) < n:
#                    if visited[x+dx[i]][y+dy[i]] == False:
#                        golds.append(dfs([x+dx[i], y+dy[i]], gold, visited))
#                        #gold = max(gold, dfs([x+dx[i], y+dy[i]], gold, visited))
#            return max(golds)
#
#        
#        for s in starts:
#            #print(visited_base)
#            ans = max(ans, dfs(s, 0, visited_base))
#            #print(s, ans)
#        return ans