class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        start, end = newInterval
        ans = []
        s_index = 0
        for i in range(len(intervals)):
            if intervals[i][0] > start:
                s_index = i 
                break
            else:
                ans.append(intervals[i])
        #print("1: ", ans)
        if ans:
            if start <= ans[-1][1]:
                if ans[-1][1] < end:
                    ans[-1][1] = end
            else:
                ans.append(newInterval)
        else:
            ans = [newInterval]

        #print("2: ", ans)
        for i in range(s_index, len(intervals)):
            if intervals[i][0] <= ans[-1][1]:
                if ans[-1][1] <= intervals[i][1]:
                    ans[-1][1] = intervals[i][1]
            else:
                ans += intervals[i:]
                break
        return ans