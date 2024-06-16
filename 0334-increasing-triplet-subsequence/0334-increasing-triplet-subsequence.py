class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        first, second = 2 ** 31, 2 ** 31
        for i in range(len(nums)):
            if nums[i] <= first:
                first = nums[i]
            elif nums[i] <= second:
                second = nums[i]
            elif nums[i] > second:
                return True
        return False


        #n = len(nums)
        #for i in range(n-2):
        #    for j in range(i+1, n-1):
        #        for k in range(j+1, n):
        #            if nums[i] < nums[j] and nums[j] < nums[k]:
        #                return True
        #return False
