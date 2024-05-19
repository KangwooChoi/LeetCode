class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        dp = [0] * (len(nums) - k + 1)
        dp[0] = sum(nums[:k])
        for i in range(1, len(nums)-k+1): 
            dp[i] = dp[i-1] + nums[i+k-1] - nums[i-1]
        return max(dp) / float(k)