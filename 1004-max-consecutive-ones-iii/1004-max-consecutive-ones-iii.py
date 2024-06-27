class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        from collections import deque
        start = 0
        ans = 0
        zeroes = deque()
        for end in range(len(nums)):
            if nums[end] == 0:
                zeroes.append(end)
                if len(zeroes) > k:
                    start = zeroes.popleft() + 1
            ans = max(ans, end - start + 1)
        return ans