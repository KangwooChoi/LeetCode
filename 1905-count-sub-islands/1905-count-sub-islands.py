class Solution:
    def isSubIsland(self, grid1: List[List[int]], island: List[List[int]]) -> bool:
        for x, y in island:
            if grid1[x][y] == 0:
                return False
        return True
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m, n = len(grid1), len(grid1[0])
        visited = [[False] * n for _ in range(m)]
        islands = []
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        for i in range(m):
            for j in range(n):
                if visited[i][j]:
                    continue
                visited[i][j] = True
                if grid2[i][j] == 0:
                    continue
                dq = deque([(i, j)])
                island = []
                while dq:
                    now = dq.popleft()
                    island.append(now)
                    x, y = now
                    for k in range(4):
                        nx, ny = x+dx[k], y+dy[k]
                        if 0 <= nx < m and 0 <= ny < n:
                            if visited[nx][ny] == True:
                                continue
                            visited[nx][ny] = True
                            if grid2[nx][ny] == 1:
                                dq.append((nx, ny))
                islands.append(island)
        print(islands)
        ans = 0
        for island in islands:
            if self.isSubIsland(grid1, island):
                ans += 1
        return ans 