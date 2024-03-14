class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #if len(nums) <= 1:
        #    return len(nums)
        now_val = nums[0]
        next_index = 1
        replace_index = 1
        while next_index < len(nums):
            if now_val != nums[next_index]:
                now_val = nums[next_index]
                nums[replace_index] = nums[next_index]
                replace_index += 1
            next_index += 1
        #for i in range(replace_index, len(nums)):
        #    nums.pop()
        print('nums: ', nums)
        return replace_index
