class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        nums.sort()
        print(nums)
        cnt = 1
        max_cnt = 0
        ans = None
        for i in range(0, len(nums)-1):
            if nums[i] == nums[i+1]:
                cnt += 1
            else:
                cnt = 1
            if max_cnt < cnt:
                max_cnt = cnt
                ans = nums[i]
        return ans


        #from collections import Counter
        #return Counter(nums).most_common()[0][0]
