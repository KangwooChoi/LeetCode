class Solution:
    def canChange(self, start: str, target: str) -> bool:
        start_deq = deque()
        n = len(start)
        for i in range(n):
            if start[i] == 'L' or start[i] == 'R':
                start_deq.append([start[i], i])
        for j in range(n):
            if target[j] == 'L':
                if len(start_deq) == 0:
                    return False
                ch, loc = start_deq.popleft()
                if ch != 'L':
                    return False
                if loc < j:
                    return False
            if target[j] == 'R':
                if len(start_deq) == 0:
                    return False
                ch, loc = start_deq.popleft()
                if ch != 'R':
                    return False
                if loc > j:
                    return False
        if len(start_deq) == 0:
            return True
        return False