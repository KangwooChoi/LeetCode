class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        if n == 0:
            return []
        if n == 1:
            return [str(nums[0])] 
        ans = [[nums[0],nums[0]]]
        for i in range(1, n):
            if nums[i] == nums[i-1] + 1:
                ans[-1][1] = nums[i]
            else:
                ans.append([nums[i], nums[i]])
        for i in range(len(ans)):
            src, dest = ans[i]
            if src != dest:
                ans[i] = str(src) + "->" + str(dest)
            else:
                ans[i] = str(src)
        return ans

