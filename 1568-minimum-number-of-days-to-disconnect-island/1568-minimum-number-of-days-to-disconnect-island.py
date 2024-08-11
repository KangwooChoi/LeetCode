class Solution:
    DIRECTIONS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def minDays(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
    
        init_cnt = self._count_islands(grid)
        if init_cnt != 1:
            return 0
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 0:
                    continue
                grid[row][col] = 0
                new_cnt = self._count_islands(grid)
                if new_cnt != 1:
                    return 1 
                grid[row][col] = 1
        return 2
    
    def _count_islands(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        visited = [[False for _ in range(cols)] for _ in range(rows)]
        island_count = 0
        for row in range(rows):
            for col in range(cols):
                if not visited[row][col] and grid[row][col] == 1:
                    self._explore_island(grid, row, col, visited)
                    island_count += 1
        return island_count
    
    def _explore_island(self, grid: List[List[int]], row: int, col: int, visited: List[List[bool]]) -> None:
        visited[row][col] = True
        for dir in self.DIRECTIONS:
            new_row = row + dir[0]
            new_col = col + dir[1]
            if self._is_valid_land_cell(grid, new_row, new_col, visited):
                self._explore_island(grid, new_row, new_col, visited)

    def _is_valid_land_cell(self, grid: List[List[int]], row: int, col: int, visited: List[List[bool]],) -> bool:
        rows = len(grid)
        cols = len(grid[0])
        return (
            0 <= row < rows
            and 0 <= col < cols
            and grid[row][col] == 1
            and not visited[row][col]
        ) 