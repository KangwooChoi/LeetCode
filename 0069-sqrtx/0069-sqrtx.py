class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 1:
            return 0
        if x < 2:
            return 1
        for i in range(2, x//2+2):
            if i*i > x:
                return i-1

             