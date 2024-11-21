class Solution:
    def _dfs(
        self, row: int, col: int, grid: List[List[int]], direction: str
    ) -> None:
        if (
            row < 0
            or row >= len(grid)
            or col < 0
            or col >= len(grid[0])
            or grid[row][col] in (2, 3)
        ):
            return
        grid[row][col] = 1  # Mark cell as guarded
        if direction == "U":
            self._dfs(row - 1, col, grid, "U")  # Up
        elif direction == "D":
            self._dfs(row + 1, col, grid, "D")  # Down
        elif direction == "L":
            self._dfs(row, col - 1, grid, "L")  # Left
        elif direction == "R":
            self._dfs(row, col + 1, grid, "R")  # Right

    def countUnguarded(
        self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]
    ) -> int:
        grid = [[0] * n for _ in range(m)]

        # Mark guards' positions
        for guard in guards:
            grid[guard[0]][guard[1]] = 2

        # Mark walls' positions
        for wall in walls:
            grid[wall[0]][wall[1]] = 3

        # Mark cells as guarded by traversing from each guard
        for guard in guards:
            self._dfs(guard[0] - 1, guard[1], grid, "U")  # Up
            self._dfs(guard[0] + 1, guard[1], grid, "D")  # Down
            self._dfs(guard[0], guard[1] - 1, grid, "L")  # Left
            self._dfs(guard[0], guard[1] + 1, grid, "R")  # Right

        # Count unguarded cells
        count = 0
        for row in grid:
            for cell in row:
                if cell == 0:
                    count += 1
        return count
#class Solution:
#    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
#        map_arr = [[1] * n for _ in range(m)]
#        for x, j in walls:
#            map_arr[x][j] = -1
#        dx = [-1, 0, 1, 0]
#        dy = [0, 1, 0, -1]
#        for guard_x, guard_y in guards:
#            map_arr[guard_x][guard_y] = 0
#            for i in range(4):
#                nx, ny = guard_x, guard_y
#                while (
#                    0 <= nx + dx[i] < m
#                    and 0<= ny + dy[i] < n
#                    and map_arr[nx+dx[i]][ny+dy[i]] != -1
#                ):
#                    nx, ny = nx+dx[i], ny+dy[i]
#                    map_arr[nx][ny] = 0
#        
#        #print(map_arr)
#        ans = 0
#        for row in map_arr:
#            ans += sum(row)
#        ans += len(walls)
#        return ans