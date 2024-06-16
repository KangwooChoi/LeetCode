class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        ans = 0
        miss = 1
        index = 0
        while miss <= n: 
            if index < len(nums) and nums[index] <= miss:
                miss += nums[index]
                index += 1
            else:
                ans += 1
                miss += miss
        return ans
