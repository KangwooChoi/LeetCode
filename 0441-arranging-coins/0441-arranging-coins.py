class Solution:
    def arrangeCoins(self, n: int) -> int:
        left, right = 0, n
        ans = 0
        while left <= right:
            mid = (left + right) // 2
            if n >= ((mid*(mid+1))//2):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans

        #stair = 0
        #while n >= 0:
        #    stair += 1
        #    if n >= stair:
        #        n -= stair
        #    else:
        #        return stair - 1