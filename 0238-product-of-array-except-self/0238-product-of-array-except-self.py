class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        ans[0] = 1
        for i in range(1, n):
            ans[i] = ans[i-1] * nums[i-1]
        right = 1
        for i in reversed(range(n)):
            ans[i] = ans[i] * right
            right *= nums[i]
        return ans

        #def recursive(prev_prod, index):
        #    if index == len(nums) -1:
        #        ans[-1] = prev_prod
        #        return nums[-1] 
        #    temp_prev = prev_prod
        #    prev_prod *= nums[index]
        #    post_prod = recursive(prev_prod, index+1)
        #    ans[index] = temp_prev * post_prod
        #    return post_prod*nums[index]
        #zero_cnt = 0
        #prod = 1
        #for i, n in enumerate(nums):
        #    if n == 0:
        #        if zero_cnt == 1:
        #            return [0] * len(nums)
        #        else:
        #            loc = i    
        #            continue
        #    prod *= n
        #if zero_cnt == 1:
        #    ans = [0] * len(nums)
        #    ans[i] = prod
        #else:
        #    ans = [1] * len(nums)
        #    recursive(1, 0)
        #return ans
