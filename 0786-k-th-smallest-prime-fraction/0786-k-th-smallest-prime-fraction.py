class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        from heapq import heappop, heappush
        queue = []
        for j in range(len(arr)-1, -1, -1):
            for i in range(j):
                heappush(queue, (arr[i]/arr[j], [arr[i], arr[j]]))
        cnt = 1
        while cnt < k:
            heappop(queue)
            cnt += 1
        return heappop(queue)[1]