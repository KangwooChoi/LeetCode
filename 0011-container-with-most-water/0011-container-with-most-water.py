class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        ans = 0
        for i in range(n):
            for j in range(n-1, i, -1):
                ans = max(ans, (j-i) * min(height[j], height[i]))
                if height[i] <= height[j]:
                    break
        return ans