class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        ans = 0
        now = 0
        for i in gain:
            now += i
            ans = max(now, ans)
        return ans