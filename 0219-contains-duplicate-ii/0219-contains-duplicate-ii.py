class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        counter = defaultdict(int) 
        for i in range(len(nums)):
            if i > k:
                counter[nums[i-k-1]] -= 1
            key = nums[i]
            if key in counter and counter[key] == 1:
                return True
            else:
                counter[key] = 1
        return False
