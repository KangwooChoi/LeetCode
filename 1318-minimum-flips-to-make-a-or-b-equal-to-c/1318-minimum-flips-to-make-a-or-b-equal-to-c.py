class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        counter = [0] * 32 
        index = 0 
        flip = 0
        while a > 0 or b > 0 or c > 0:
            count = a % 2 + b % 2
            if c % 2 == 0 and count:
                flip += count
            if c % 2 and count == 0:
                flip += 1
            a //= 2
            b //= 2
            c //= 2
        return flip

             
