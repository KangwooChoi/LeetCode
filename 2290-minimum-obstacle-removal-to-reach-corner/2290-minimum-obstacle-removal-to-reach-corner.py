class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        INF = int(1e9)
        m, n = len(grid), len(grid[0])
        visited =  [[INF] * n for _ in range(m)]
        cost_heap = []
        heapq.heappush(cost_heap, [0, 0, 0])
        dx = [-1, 0, 1, 0]
        dy = [0, -1, 0, 1]
        while cost_heap:
            #print(cost_heap)
            cost, x, y = heapq.heappop(cost_heap)
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx == m - 1 and ny == n - 1:
                    return cost
                if (0 <= nx < m) and (0 <= ny < n):
                    if visited[nx][ny] > (cost + grid[nx][ny]):
                        heapq.heappush(cost_heap, [cost + grid[nx][ny], nx, ny])
                        visited[nx][ny] = cost + grid[nx][ny]
        return -1 