class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        ans = time % (2 * n - 2) 
        if ans <= (n - 1):
            return ans + 1
        ans -= (n - 1)
        return n - ans
