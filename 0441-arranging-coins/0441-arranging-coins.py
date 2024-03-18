class Solution:
    def arrangeCoins(self, n: int) -> int:
        stair = 0
        while n >= 0:
            stair += 1
            if n >= stair:
                n -= stair
            else:
                return stair - 1