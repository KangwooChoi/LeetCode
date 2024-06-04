class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = []
        for i in range(n+1):
            cnt = 0
            while i > 0:
                cnt += i % 2
                i //= 2
            ans.append(cnt)
        return ans
