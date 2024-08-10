class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        def dfs(i: int, j: int) -> int:
            if min(i, j) < 0 or max(i, j) >= len(g) or g[i][j] != 0:
                return 0
            g[i][j] = 1
            return 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1)
        n, regions  = len(grid), 0
        g = [[0] * n * 3 for i in range(n * 3)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == '/':
                    g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1
                elif grid[i][j] == '\\':
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1
        for i in range(n * 3):
            for j in range(n * 3):
                regions += 1 if dfs(i, j) > 0 else 0
        return regions
#class Solution:
#    def regionsBySlashes(self, grid: List[str]) -> int:
#        def checkPath(graph, start, end):
#            pass
#        n = len(grid) + 1
#        graph = [[] for _ in range(n*n+1)]
#        # outer
#        for i in range(1, n):
#            # upper
#            graph[i].append(i+1)
#            graph[i+1].append(i)
#            # lower
#            graph[]
#            # left
#            graph[(n+1)*i].append((n+1)*(i+1))
#            graph[(n+1)*i].append((n+1)*(i+1))