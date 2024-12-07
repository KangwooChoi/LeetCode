class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        left = 1
        right = max(nums)
        nums.sort(reverse=True)

        while left < right:
            middle = (left + right) // 2
            if self._is_possible(middle, nums, maxOperations):
                right = middle
            else:
                left = middle + 1
        
        return left

    def _is_possible(self, max_balls_in_bag, nums, max_operations):
        total_operations = 0
        for num in nums:
            if num <= max_balls_in_bag:
                break
            operations = math.ceil(num / max_balls_in_bag) - 1
            total_operations += operations

            if total_operations > max_operations:
                return False
                
        return True
#        nums.sort(reverse=True)
#        print(nums)
#        left, right = 1, nums[0]
#        mid = (left + right) // 2
#        ans = nums[0]
#        while left < right:
#            cnt = 0
#            flag = True
#            for num in nums:
#                if num <= mid:
#                    ans = mid
#                    flag = True
#                    break
#                cnt += num // mid - 1
#                if num % mid != 0:
#                    cnt += 1
#                if cnt > maxOperations:
#                    if left + 1 == ans:
#                        return ans
#                    flag = False
#                    left = mid
#                    mid = (left + right) // 2
#                    break
#            if flag:
#                ans = mid
#                right = mid
#                mid = (left + right) // 2
#            
#        return ans