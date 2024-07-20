class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        from heapq import heappop, heappush
        row_heap = []
        col_heap = []
        m = len(rowSum)
        n = len(colSum)
        for i in range(len(rowSum)):
            heappush(row_heap, [rowSum[i], i])
        for j in range(len(colSum)):
            heappush(col_heap, [colSum[j], j])
        ans = [[0] * n for _ in range(m)]
        while row_heap and col_heap:
            #print(ans)
            x, y = row_heap[0][1], col_heap[0][1]
            if row_heap[0][0] <= col_heap[0][0]:
                val, pos = heappop(row_heap)
                col_heap[0][0] -= val
            else:
                val, pos = heappop(col_heap)
                row_heap[0][0] -= val
            ans[x][y] = val
        return ans