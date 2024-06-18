class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        from heapq import heappop, heappush
        worker.sort() 
        prof_diff = []
        n = len(difficulty)
        for i in range(n):
            heappush(prof_diff, [-profit[i], difficulty[i]])
        ans = 0
        w = worker.pop()
        p, d = heappop(prof_diff)
        while w and -p and d:
            if w >= d:
                ans -= p
                if worker:
                    w = worker.pop()            
                else:
                    break
            else:
                if prof_diff:
                    p, d = heappop(prof_diff)
                else:
                    break

        return ans



            
