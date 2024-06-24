class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        from collections import deque
        def find(target):
            left, right = 0, len(flip) - 1
            while left <= right:
                mid = (left + right) // 2
                if flip[mid] == target:
                    return mid + 1
                elif flip[mid] > target:
                    right = mid - 1
                else:
                    left = mid + 1
            if flip[mid] > target:
                #print("mid: ", mid)
                #print("flip[mid], target: ", flip[mid], target)
                return mid 
            else:
                #print("mid+1: ", mid+1)
                #print("flip[mid], target: ", flip[mid], target)
                return mid + 1

        ans = 0
        flip = deque()
        for i in range(len(nums)): 
            #print("i: ", i)
            #print(flip, nums[i])
            if flip and flip[0] <= i - k:
                flip.popleft()
            #print(flip, nums[i])
            if flip:
                nums[i] += find(i) 
            #print(flip, nums[i])
            if nums[i] % 2 == 0:
                if i + k <= len(nums):
                    ans += 1
                    flip.append(i)
                else:
                    return -1
        return ans
            



