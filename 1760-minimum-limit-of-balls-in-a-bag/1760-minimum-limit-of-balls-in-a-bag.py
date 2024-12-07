class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        nums.sort(reverse=True)
        print(nums)
        left, right = 1, nums[0]
        mid = (left + right) // 2
        ans = nums[0]
        while left < right:
            cnt = 0
            flag = True
            for num in nums:
                if num <= mid:
                    ans = mid
                    flag = True
                    break
                cnt += num // mid - 1
                if num % mid != 0:
                    cnt += 1
                if cnt > maxOperations:
                    if left + 1 == ans:
                        return ans
                    flag = False
                    left = mid
                    mid = (left + right) // 2
                    break
            if flag:
                ans = mid
                right = mid
                mid = (left + right) // 2
            
        return ans