# We're gonna use Union Find
# Each time a new island is placed, check if it's actually part of another island
# No matter how many islands it's added to, all are merged into 1 island
#   If new land is connected to 4 existent islands, we now have 1, so -3
#   If new land is connected to 3 existent islands, we now have 1, so -2
#   If new land is connected to 2 existent islands, we now have 1, so -1
#   If new land is connected to 1 existent island, we now have 1, so 0
#   If new land is connected to 0 existent island, we now have 1, so +1

class UnionFind:
    def __init__(self, n):
        self.root = list(range(n))
        self.rank = [0] * n

    def find(self, node):
        if self.root[node] == node:
            return node
        else:
            self.root[node] = self.find(self.root[node])
            return self.root[node]

    def union(self, node1, node2):
        root1 = self.find(node1)
        root2 = self.find(node2)

        if self.rank[root1] > self.rank[root2]:
            self.root[root2] = self.root[root1]
        elif self.rank[root1] < self.rank[root2]:
            self.root[root1] = self.root[root2]
        else:
            self.root[root2] = self.root[root1]
            self.rank[root1] += 1

    def is_connected(self, node1, node2):
        return self.find(node1) == self.find(node2)

class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        dsu = UnionFind(m * n)
        grid = [[0] * n for _ in range(m)]
        islands = 0
        ans = [0] * len(positions)

        for i, (new_r, new_c) in enumerate(positions):
            # skip repeated islands by doing nothing if it's already an island
            if grid[new_r][new_c]:
                ans[i] = islands
                continue
            if grid[new_r][new_c]:
                ans[i] = islands
                continue

            connected = 0
            grid[new_r][new_c] = 1
            for old_r, old_c in ((new_r + 1, new_c), (new_r - 1, new_c), (new_r, new_c + 1), (new_r, new_c - 1)):
                if old_r in range(m) and old_c in range(n) and grid[old_r][old_c]:
                    new_land = n * new_r + new_c
                    old_land = n * old_r + old_c
                    if not dsu.is_connected(old_land, new_land):
                        connected += 1
                        dsu.union(old_land, new_land)

            islands += 1 - connected
            ans[i] = islands

        return ans

#class Solution:
    #def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
#
    #    from collections import deque
    #    def findparents(parents, x, y, val):
    #        dq = deque([])
    #        dq.append((x,y))
    #        while dq:
    #            tx, ty = dq.popleft()
    #            parents[tx][ty] = val
    #            for i in range(4):
    #                if 0 <= tx+dx[i] < m and 0 <= ty+dy[i] < n:
    #                    if parents[tx+dx[i]][ty+dy[i]] > val:
    #                        dq.append((tx+dx[i], ty+dy[i]))
#
    #    parents = [[0] * n for _ in range(m)]
    #    #print(parents)
    #    dx = [0, 0, -1, 1]
    #    dy = [-1, 1, 0, 0]
    #    ans = [1]
    #    parents[positions[0][0]][positions[0][1]] = 1
    #    for index, p in enumerate(positions[1:]):
    #        x, y = p
    #        if parents[x][y]:
    #            ans.append(ans[-1])
    #            continue
    #        temp = set()
    #        for i in range(4):
    #            if 0 <= x+dx[i] < m and 0 <= y+dy[i] < n:
    #                if parents[x+dx[i]][y+dy[i]]:
    #                    temp.add(parents[x+dx[i]][y+dy[i]])
    #        print("x, y, temp: ", x, y, temp)
    #        if len(temp) == 0:
    #            parents[x][y] = index + 2
    #        else:
    #            parents[x][y] = min(temp)
    #            for i in range(4):
    #                if 0 <= x+dx[i] < m and 0 <= y+dy[i] < n:
    #                    if parents[x+dx[i]][y+dy[i]] > min(temp):
    #                        findparents(parents, x+dx[i], y+dy[i], min(temp))
    #        
    #        ans.append(ans[-1] - len(temp) + 1)
#
    #    return ans