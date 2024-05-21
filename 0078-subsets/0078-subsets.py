class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        from itertools import combinations
        ans = []
        n = len(nums)
        for i in range(n+1):
            ans += map(list, combinations(nums, i))
        return ans
