class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        def twoSum(array, target):
            print("target: ", target)
            left, right = 0, len(array) - 1
            ans = []
            while left < right:
                base = array[left] + array[right]
                if base > target:
                    right -= 1
                elif base < target:
                    left += 1
                else:
                    print(left, right)
                    ans.append([-target, array[left], array[right]])
                    left += 1
                    right -= 1
            return ans

        nums.sort()
        print(nums)
        ans = []
        for i in range(len(nums)):
            if nums[i] > 0:
                return ans
            if i >= 1 and nums[i] == nums[i-1]:
                continue
            ans += twoSum(nums[i+1:], -nums[i])
        return ans