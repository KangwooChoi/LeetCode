class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        from collections import deque
        def bfs(tx, ty):
            dq = deque()
            dq.append((tx, ty))
            while dq:
                x, y = dq.popleft()
                if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[0]):
                    continue
                if visited[x][y]:
                    continue
                visited[x][y] = 1
                #print("visited: ", visited)
                ans[0] += 4
                #print("ans: ", ans[0]) 
                for i in range(4):
                    nx, ny = x+dx[i], y+dy[i] 
                    if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]):
                        if grid[nx][ny]:        # island
                            ans[0] -= 1
                            if not visited[nx][ny]:
                                dq.append([nx, ny])

        visited = [[0] * len(grid[0]) for _ in range(len(grid))]
        #print(visited)
        ans = [0]
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        flag = False
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if not visited[i][j]:
                    if grid[i][j]:
                        #print("call bfs: i, j : ", i, j)
                        bfs(i, j)
                        flag = True
                        break
            if flag:
                break

        return ans[0] 