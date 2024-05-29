class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        if k == 1:
            return '4'
        if k == 2:
            return '7'
        cnt, i = 0, 0
        while cnt < k:
            i += 1
            cnt += 2**i
        left, right = cnt - 2**i, cnt
        ans = '4'*i
        loc = 0
        while left <= right:
            mid = (left + right) // 2
            if mid < k:
                ans = ans[:loc] + '7' + ans[loc+1:]
                left = mid
            elif mid > k:
                ans = ans[:loc] + '4' + ans[loc+1:]
                right = mid
            else:
                ans = ans[:loc] + '4' + '7' * len(ans[loc+1:])
                return ans
            loc += 1