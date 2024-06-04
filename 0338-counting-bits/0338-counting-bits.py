class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0] * (n+1)
        order = 1
        for i in range(1, n+1):
            if i == 2 ** order:
                ans[i] = 1
                order += 1
            else:
                ans[i] = ans[i-2**(order-1)] + 1
        return ans

        #ans = []
        #for i in range(n+1):
        #    cnt = 0
        #    while i > 0:
        #        cnt += i % 2
        #        i //= 2
        #    ans.append(cnt)
        #return ans
