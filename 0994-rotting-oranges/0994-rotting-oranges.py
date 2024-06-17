class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        from collections import deque
        m = len(grid)
        n = len(grid[0]) 
        queue = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    queue.append([i, j])
        if not queue:
            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 1:
                        return -1
            return 0
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        curr_time = 3
        while queue:
            x, y = queue.popleft()
            for i in range(4):
                nx = x + dx[i]           
                ny = y + dy[i]
                if 0 <= nx < m and 0 <= ny < n:
                    if grid[nx][ny] == 1 or grid[nx][ny] > grid[x][y]:
                        grid[nx][ny] = grid[x][y] + 1
                        queue.append([nx, ny]) 
        maximum = 2
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1
                maximum = max(maximum, grid[i][j])

        return maximum - 2   
