class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        for i in range(n):
            if nums[i] >= n - i:
                return n - i
        return -1