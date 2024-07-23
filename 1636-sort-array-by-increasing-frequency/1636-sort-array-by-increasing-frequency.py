class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        from heapq import heappush, heappop

        counter = defaultdict(int)
        for num in nums:
            counter[num] += 1
        hq = []
        for key in counter:
            heappush(hq, (counter[key], -key))
        ans = []
        while hq:
            cnt, val = heappop(hq)
            ans += [-val] * cnt
        
        return ans