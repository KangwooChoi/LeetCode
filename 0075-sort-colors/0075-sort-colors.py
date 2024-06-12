class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #nums.sort()
        counter = [0, 0, 0]
        for color in nums:
            counter[color] += 1
        start = 0
        for i, cnt in enumerate(counter):
            for j in range(start, start+cnt):
                nums[j] = i
            start += cnt
        
        