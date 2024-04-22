class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:

        from collections import deque
        def findparents(parents, x, y, val):
            dq = deque([])
            dq.append((x,y))
            while dq:
                tx, ty = dq.popleft()
                parents[tx][ty] = val
                for i in range(4):
                    if 0 <= tx+dx[i] < m and 0 <= ty+dy[i] < n:
                        if parents[tx+dx[i]][ty+dy[i]] > val:
                            dq.append((tx+dx[i], ty+dy[i]))

        parents = [[0] * n for _ in range(m)]
        #print(parents)
        dx = [0, 0, -1, 1]
        dy = [-1, 1, 0, 0]
        ans = [1]
        parents[positions[0][0]][positions[0][1]] = 1
        for index, p in enumerate(positions[1:]):
            x, y = p
            if parents[x][y]:
                ans.append(ans[-1])
                continue
            temp = set()
            for i in range(4):
                if 0 <= x+dx[i] < m and 0 <= y+dy[i] < n:
                    if parents[x+dx[i]][y+dy[i]]:
                        temp.add(parents[x+dx[i]][y+dy[i]])
            print("x, y, temp: ", x, y, temp)
            if len(temp) == 0:
                parents[x][y] = index + 2
            else:
                parents[x][y] = min(temp)
                for i in range(4):
                    if 0 <= x+dx[i] < m and 0 <= y+dy[i] < n:
                        if parents[x+dx[i]][y+dy[i]] > min(temp):
                            findparents(parents, x+dx[i], y+dy[i], min(temp))
            
            ans.append(ans[-1] - len(temp) + 1)

        return ans