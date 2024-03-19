class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        nums = sorted([num**2 for num in nums])
        return nums 