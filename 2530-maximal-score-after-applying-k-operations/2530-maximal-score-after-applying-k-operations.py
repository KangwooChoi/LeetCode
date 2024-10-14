class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        heap = []
        for num in nums:
            heapq.heappush(heap, -num)
        ans = 0
        for i in range(k):
            score = -1 * heapq.heappop(heap)
            ans += score
            new = score // 3 if score % 3 == 0 else score // 3 + 1
            heapq.heappush(heap, -new)
        return ans