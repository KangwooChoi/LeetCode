class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        sorted_h = sorted(heights)
        ans = 0
        for i in range(len(heights)):
            if sorted_h[i] != heights[i]:
                ans += 1
        return ans