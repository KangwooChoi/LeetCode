class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        def recursive(prev_prod, index):
            if index == len(nums) -1:
                ans[-1] = prev_prod
                return nums[-1] 
            temp_prev = prev_prod
            prev_prod *= nums[index]
            post_prod = recursive(prev_prod, index+1)
            ans[index] = temp_prev * post_prod
            return post_prod*nums[index]
            
        ans = [1] * len(nums)
        recursive(1, 0)
        return ans
