class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        from collections import Counter
        counter = Counter(nums)
        ans = 0 
        keys = sorted(counter.keys())
        left, right = 0, len(keys)-1
        while left < right:
            if keys[left] + keys[right] == k:
                ans += min(counter[keys[left]], counter[keys[right]])
                left += 1
                right -= 1
                continue
            if keys[left] + keys[right] > k:
                right -= 1
            else:
                left += 1
        if k % 2 == 0:
            ans += counter[k//2] // 2
        return ans
        #counter = defaultdict(int)
        #ans = 0
        #for i in range(len(nums)):
        #    if nums[i] >= k:
        #        continue
        #    counter[nums[i]] += 1
        #left, right = 1, k-1
        #while left < right:
        #    ans += min(counter[left], counter[right])
        #    left += 1
        #    right -= 1
        #if k % 2 == 0:
        #    ans += counter[k//2] // 2
        #return ans