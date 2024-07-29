class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        n = len(prob)
        dp = [[0.] * (target + 1) for _ in range(n + 1)]
        dp[0][0] = 1.

        for pos in range(1, n + 1):
            dp[pos][0] = dp[pos-1][0] * (1 - prob[pos-1])
            for cnt in range(1, target + 1):
                if cnt > pos:
                    break
                dp[pos][cnt] = dp[pos-1][cnt-1] * prob[pos-1] + dp[pos-1][cnt] * (1. - prob[pos-1])
        
        return dp[n][target]