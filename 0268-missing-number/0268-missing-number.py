class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort(reverse=True) 
        comp = len(nums)
        for num in nums:
            if num != comp:
                return comp
            comp -= 1
        return comp