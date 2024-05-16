class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        ans = 1
        room[0][0] = 2
        dx = [0, 1, 0, -1] 
        dy = [1, 0, -1, 0]
        x, y, i = 0, 0, 0
        m, n = len(room), len(room[0])
        cnt = 0
        while True:
            nx, ny = x+dx[i], y+dy[i]
            if 0 <= nx < m and 0 <= ny < n:
                if room[nx][ny] == 1:
                    cnt += 1
                    i += 1
                    i %= 4
                    if cnt == 4:
                        return ans
                elif room[nx][ny] == 2:
                    if cnt > min(m, n):
                        return ans
                    x, y = nx, ny
                    cnt += 1
                elif room[nx][ny] == 0:
                    cnt = 0
                    room[nx][ny] = 2
                    x, y = nx, ny
                    ans += 1
            else:
                cnt += 1
                if cnt == 4:
                    return ans
                i += 1
                i %= 4