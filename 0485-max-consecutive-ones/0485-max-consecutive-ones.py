class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_num = 0
        current = 0
        for num in nums:
            if num == 1: 
                current += 1
            else:
                if current > max_num:
                    max_num = current
                current = 0
        return max_num if max_num > current else current