class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        ans = 0
        cnt = 0
        happiness.sort(reverse=True)
        for happy in happiness:
            if happy >= cnt and cnt < k:
                #print(happy, cnt, k)
                ans += happy
                cnt += 1
            else:
                break
        return ans - cnt*(cnt-1)//2