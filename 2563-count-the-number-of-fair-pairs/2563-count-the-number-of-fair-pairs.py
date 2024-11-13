class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        return self.lower_bound(nums, upper + 1) - self.lower_bound(nums, lower)

    # Calculate the number of pairs with sum less than `value`.
    def lower_bound(self, nums: List[int], value: int) -> int:
        left = 0
        right = nums.__len__() - 1
        result = 0
        while left < right:
            sum = nums[left] + nums[right]
            # If sum is less than value, add the size of window to result and move to the
            # next index.
            if sum < value:
                result += right - left
                left += 1
            else:
                # Otherwise, shift the right pointer backwards, until we get a valid window.
                right -= 1
        return result
#class Solution:
#    def lower_bound(self, nums, low, high, element):
#        n = 0
#        while low <= high:
#            mid = low + ((high - low) // 2)
#            if nums[mid] >= element:
#                high = mid - 1
#            else:
#                low = mid + 1
#        return low
#
#    def countFairPairs(self, nums, lower, upper):
#        nums.sort()
#        ans = 0
#        for i in range(len(nums)):
#            # Assume we have picked nums[i] as the first pair element.
#
#            # `low` indicates the number of possible pairs with sum < lower.
#            low = self.lower_bound(nums, i + 1, len(nums) - 1, lower - nums[i])
#
#            # `high` indicates the number of possible pairs with sum <= upper.
#            high = self.lower_bound(
#                nums, i + 1, len(nums) - 1, upper - nums[i] + 1
#            )
#
#            # Their difference gives the number of elements with sum in the
#            # given range.
#            ans += high - low
#
#        return ans