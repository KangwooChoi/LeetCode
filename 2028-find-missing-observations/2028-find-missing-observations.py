class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        target = mean * (len(rolls) + n) - sum(rolls)
        p, q = target // n, target % n
        ans = []
        if q == 0:
            if p > 6 or p < 1:
                return ans
        if q != 0:
            if p > 5 or p < 1:
                return ans
                
        for _ in range(q):
            ans.append(p+1)
        for _ in range(n-q):
            ans.append(p)
        return ans