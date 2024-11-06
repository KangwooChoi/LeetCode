class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        prev_max, curr_max = 0, nums[0] 
        curr_bit_cnt = nums[0].bit_count() 
        for i in range(1, n):
            if curr_bit_cnt != nums[i].bit_count():
                curr_bit_cnt = nums[i].bit_count()
                prev_max = curr_max
                if nums[i] < prev_max:
                    return False
                curr_max = nums[i]
            else:
                if nums[i] < prev_max:
                    return False  
                if nums[i] > curr_max:
                    curr_max = nums[i]
        return True