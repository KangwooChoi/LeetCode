class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        nums.sort()
        processed_nums = set()
        ans = 0
        for num in nums:
            if num in processed_nums:
                continue
            
            curr = num
            curr_length = 1

            while curr*curr <= 10**5:
                if self._bin_search(nums, curr*curr):
                    curr *= curr
                    processed_nums.add(curr)
                    curr_length += 1
                else:
                    break
            
            ans = max(ans, curr_length)
        return ans if ans >= 2 else -1
    
    def _bin_search(self, nums, target):
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return False