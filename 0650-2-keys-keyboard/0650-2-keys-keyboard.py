class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0
        ans = 0
        while n > 1:
            for i in range(2, 1000):
                if n % i == 0:
                    ans += i
                    break
            n //= i
        return ans       