class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        N = len(nums)

        lis_length = [1] * N

        for i in range(N):
            for j in range(i):
                if nums[i] > nums[j]:
                    lis_length[i] = max(lis_length[i], lis_length[j] + 1) 

        return max(lis_length) 