class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left , right = 0, len(numbers) - 1 
        while left < right:
            base = numbers[left] + numbers[right]
            if base > target:
                right -= 1
            elif base < target: 
                left += 1
            else:
                return [left + 1, right + 1]
