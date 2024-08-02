class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        length = sum(nums)
        new_nums = nums * 3
        n = len(nums)
        zeros = length - sum(new_nums[n-length+1:n+1])
        ans = zeros
        #print(zeros)
        #print(new_nums)
        for i in range(n+1, 2*n+length):
            if new_nums[i] == 0:
                zeros += 1
            if new_nums[i-length] == 0:
                zeros -= 1
            ans = min(ans, zeros)

        return ans