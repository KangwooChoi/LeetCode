class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        from collections import deque
        n = len(rooms)
        visited = [False] * n
        keys = [False] * n
        queue = deque() 
        visited[0] = True
        keys[0] = True
        queue.append(0)
        while queue:
            now = queue.pop()
            visited[now] = True
            new_keys = rooms[now]
            for key in new_keys:
                if not visited[key] and not keys[key]:
                    queue.append(key)
                    keys[key] = True
        if all(visited):
            return True
        else:
            return False