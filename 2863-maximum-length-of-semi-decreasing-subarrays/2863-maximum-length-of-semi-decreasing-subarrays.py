class Solution:
    def maxSubarrayLength(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            for j in range(len(nums)-1, i+ans-1, -1):
                if nums[i] > nums[j] and ans < (j - i + 1):
                    ans = j - i + 1
                    break
        return ans