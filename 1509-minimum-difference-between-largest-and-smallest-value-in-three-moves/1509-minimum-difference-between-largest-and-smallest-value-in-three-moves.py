class Solution:
    def minDifference(self, nums: List[int]) -> int:
        from collections import deque
        if len(nums) <= 4:
            return 0
        nums.sort()
        nums = deque(nums)
        for i in range(3):
            case0 = nums[-1] - nums[3]
            case1 = nums[-2] - nums[2]
            case2 = nums[-3] - nums[1]
            case3 = nums[-4] - nums[0]
        return min(case0, case1, case2, case3)