class Solution:
    def maxLength(self, ribbons: List[int], k: int) -> int:
        left = 1 
        right = max(ribbons)
        mid = (left + right) // 2
        ans = 0
        while left <= right:
            count = 0
            for r in ribbons:
                count += r // mid
            if count >= k:
                ans = mid
                left = mid + 1
                mid = (left + right) // 2
            else:
                right = mid - 1
                mid = (left + right) // 2
        return ans 