class Solution:

    # Directions for moving to neighboring cells: right, left, down, up
    dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)

        multi_source_queue = deque()
        # Mark thieves as 0 and empty cells as -1, and push thieves to the queue
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    # Push thief coordinates to the queue
                    multi_source_queue.append((i, j))
                    # Mark thief cell with 0
                    grid[i][j] = 0
                else:
                    # Mark empty cell with -1
                    grid[i][j] = -1

        # Calculate safeness factor for each cell using BFS
        while multi_source_queue:
            size = len(multi_source_queue)
            while size > 0:
                curr = multi_source_queue.popleft()
                # Check neighboring cells
                for d in self.dir:
                    di, dj = curr[0] + d[0], curr[1] + d[1]
                    val = grid[curr[0]][curr[1]]
                    # Check if the cell is valid and unvisited
                    if self.isValidCell(grid, di, dj) and grid[di][dj] == -1:
                        # Update safeness factor and push to the queue
                        grid[di][dj] = val + 1
                        multi_source_queue.append((di, dj))
                size -= 1

        # Binary search for maximum safeness factor
        start, end, res = 0, 0, -1
        for i in range(n):
            for j in range(n):
                # Set end as the maximum safeness factor possible
                end = max(end, grid[i][j])

        while start <= end:
            mid = start + (end - start) // 2
            if self.isValidSafeness(grid, mid):
                # Store valid safeness and search for larger ones
                res = mid
                start = mid + 1
            else:
                end = mid - 1

        return res
    
    # Check if a given cell lies within the grid
    def isValidCell(self, grid, i, j) -> bool:
        n = len(grid)
        return 0 <= i < n and 0 <= j < n

    # Check if a path exists with given minimum safeness value
    def isValidSafeness(self, grid, min_safeness) -> bool:
        n = len(grid)

        # Check if the source and destination cells satisfy minimum safeness
        if grid[0][0] < min_safeness or grid[n - 1][n - 1] < min_safeness:
            return False

        traversal_queue = deque([(0, 0)])
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True

        # Breadth-first search to find a valid path
        while traversal_queue:
            curr = traversal_queue.popleft()
            if curr[0] == n - 1 and curr[1] == n - 1:
                return True  # Valid path found

            # Check neighboring cells
            for d in self.dir:
                di, dj = curr[0] + d[0], curr[1] + d[1]
                # Check if the neighboring cell is valid and unvisited
                if self.isValidCell(grid, di, dj) and not visited[di][dj] and grid[di][dj] >= min_safeness:
                    visited[di][dj] = True
                    traversal_queue.append((di, dj))

        return False  # No valid path found
#class Solution:
#    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
#        from heapq import heappop, heappush
#
#        if grid[0][0] == 1 or grid[-1][-1] == 1:
#            return 0
#
#        m, n = len(grid), len(grid[0])
#        lower = 1e9
#        thieves = []
#        ans = 0
#        for i in range(m):
#            for j in range(n):
#                if grid[i][j] == 1:
#                    dist = min(i+j, 2*n-2-i-j)
#                    lower = min(lower, dist)
#                    thieves.append([i, j])
#        # greedy + dfs
#
#        def dfs(x, y, dist):
#            #print("start dfs, x, y, dist: ", x, y, dist)
#            if x == m-1 and y == n-1:
#                #print("end: ", dist)
#                return dist
#            #dx = [-1, 1, 0, 0]
#            #dy = [0, 0, -1, 1]
#            dx = [1, 0]
#            dy = [0, 1]
#            candidates = []
#            for i in range(2):
#                temp = dist
#                nx, ny = x+dx[i], y+dy[i]
#                if 0 <= nx < m and 0 <= ny < n:
#                    flag = False
#                    for tx, ty in thieves:
#                        if nx == tx and ny == ty:
#                            flag = True
#                            break
#                        temp = min(temp, abs(tx-nx) + abs(ty-ny))
#                    if flag:
#                        continue
#                    #print("dist, nx, ny: ", temp, nx, ny)
#                    heappush(candidates, [-1*temp, nx, ny])
#            #print(candidates)
#            if not candidates:
#                return -1
#            dists = []
#            while candidates:
#                dist, i, j = heappop(candidates)
#                #print("dist, i, j: ", dist, i, j)
#                new_dist = dfs(i, j, -1*dist)
#                if new_dist == -1:
#                    return -1
#                if new_dist == lower:
#                    return lower
#                dists.append(new_dist)
#            return max(dists)
#
#        #print("lower, ans: ", lower, ans)
#        return dfs(0, 0, lower)