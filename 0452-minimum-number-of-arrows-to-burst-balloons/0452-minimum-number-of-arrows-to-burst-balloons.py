class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        from heapq import heappop, heappush
        points.sort() 
        ends = [[points[0][1], points[0][0]]]
        ans = 0
        last = 0
        for i in range(1, len(points)):
            start, end = points[i]
            if last:
                if start <= last <= end:
                    continue
            if ends and start > ends[0][0]:
                last = ends[0][0] 
                ans += 1
                ends = [[end, start]]
            elif ends and start == ends[0][0]:
                last = ends[0][0] 
                ans += 1
                ends = []
            else:
                heappush(ends, [end, start])
        
        while ends:
            end, start = heappop(ends)
            ans += 1
            while ends and end >= ends[0][1]:
                heappop(ends)
        return ans        