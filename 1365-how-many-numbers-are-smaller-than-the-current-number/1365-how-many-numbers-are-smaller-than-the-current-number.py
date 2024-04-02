class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        ## brute force
        #length = len(nums)
        #ans = []
        #for i in range(length):
        #    cnt = 0
        #    for j in range(length):
        #        if nums[i] > nums[j]:
        #            cnt += 1
        #    ans.append(cnt)
        #
        #return ans

        # hashmap
        hashmap = [0 for _ in range(101)]
        summap = [0 for _ in range(101)]
        for i in nums:
            hashmap[i] += 1
        summap[0] = hashmap[0]
        for i, cnt in enumerate(hashmap[1:]):
            summap[i+1] = summap[i] + cnt
        ans = []
        for i in nums:
            if i == 0:
                ans.append(0)
            else:
                ans.append(summap[i-1])
        return ans
