class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = []
        if a > 0:
            heapq.heappush(pq, (-a, 'a'))

        if b > 0:
            heapq.heappush(pq, (-b, 'b'))
        
        if c > 0:
            heapq.heappush(pq, (-c, 'c'))
        
        ans = ""
        while pq:
            cnt, char = heapq.heappop(pq)
            cnt = -cnt
            if len(ans) >= 2 and ans[-1] == char and ans[-2] == char:
                if not pq:
                    break
                tempCnt, tempChar = heapq.heappop(pq)
                ans += tempChar
                if (tempCnt + 1) < 0:
                    heapq.heappush(pq, (tempCnt + 1, tempChar))
                heapq.heappush(pq, (-cnt, char))
            else:
                cnt -= 1
                ans += char
                if cnt > 0:
                    heapq.heappush(pq, (-cnt, char))
        return ans