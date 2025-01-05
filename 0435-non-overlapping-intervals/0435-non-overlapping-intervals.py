class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        from heapq import heappop, heappush
        from collections import deque
        start = []
        end = []
        for s, e in intervals:
            start.append(s)
            end.append(e)
        start.sort()
        end.sort()
        start = deque(start)
        end = deque(end)
        dup, max_dup = 0, 0
        s = start.popleft()
        e = end.popleft()
        while s >= -5e4 and e >= -5e4:
            if s < e:
                dup += 1
                max_dup = max(max_dup, dup) 
                if not start:
                    return max_dup - 1
                s = start.popleft()
            if e < s:
                dup -= 1
                e = end.popleft()
            if e == s:
                if start:
                    s = start.popleft()
                    e = end.popleft()
                else:
                    return max_dup - 1
