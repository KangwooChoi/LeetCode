class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], -x[0]))

        a, b = -1, -1
        ans = 0

        for s, e in intervals:
            need =  2

            if s <= b:
                need -= 1
            if s <= a:
                need -= 1

            if need == 2:
                ans += 2
                a = e - 1
                b = e
            elif need == 1:
                ans += 1
                a = b
                b = e
        
        return ans