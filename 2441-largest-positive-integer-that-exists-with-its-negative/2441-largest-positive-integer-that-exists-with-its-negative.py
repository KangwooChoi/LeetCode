class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        from heapq import heappop, heappush
        pos = []
        neg = []
        for num in nums:
            if num > 0:
                heappush(pos, -1*num)
            else:
                heappush(neg, num)
        if pos:
            p = heappop(pos)
        else:
            return -1
        if neg:
            q = heappop(neg)
        else:
            return -1
        #print("pos: ", pos, p)
        #print("neg: ", neg, q)
        while True:
            #print("p, q: ", p, q)
            if p == q:
                return -1*p
            elif p < q:
                if pos:
                    p = heappop(pos)
                else:
                    return -1
            elif p > q:
                if neg:
                    q = heappop(neg)
                else:
                    return -1