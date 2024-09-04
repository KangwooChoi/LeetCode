class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        def checkDist(x, y):
            return x**2 + y**2
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        dir = 0
        x, y = 0, 0
        ans = 0
            
        obs_set = {x*60001 + y for x, y in obstacles}

        for c in commands:
            if c == -2:
                dir -= 1
                dir %= 4
            elif c == -1:
                dir += 1
                dir %= 4
            else:
                for _ in range(c):
                    nx, ny = x + dx[dir], y + dy[dir]
                    if nx * 60001 + ny in obs_set:
                        break
                    x, y = nx, ny
                ans = max(ans, checkDist(x, y))
        return ans