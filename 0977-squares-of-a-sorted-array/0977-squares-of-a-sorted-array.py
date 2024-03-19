class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        from heapq import heappop, heappush
        square_list = []
        for num in nums:
            heappush(square_list, num**2)
        ans = []
        while square_list:
            ans.append(heappop(square_list))
        return ans
        #nums = sorted([num**2 for num in nums])
        #return nums 