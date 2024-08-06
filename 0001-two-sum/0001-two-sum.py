class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Brute Force: Time O(n^2), Space O(1)
        #for i in range(len(nums)):
        #    for j in range(i+1, len(nums)):
        #        if target == nums[i] + nums[j]:
        #            return [i, j]

        # Two-pass Hash Table: Time O(n), Space O(n)
        #hashmap = {}
        #for i in range(len(nums)):
        #    hashmap[nums[i]] = i
        #for i in range(len(nums)):
        #    complement = target - nums[i]
        #    if complement in hashmap and i != hashmap[complement]:
        #        return [i, hashmap[complement]]
                
        # One-pass Hash Table: Time O(n), Space O(n)
        #hashmap = {}
        #for i in range(len(nums)):
        #    complement = target - nums[i]
        #    if complement in hashmap:
        #        return [i, hashmap[complement]]
        #    hashmap[nums[i]] = i


        hashmap = defaultdict(int)
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap:
                return [hashmap[complement], i]
            else:
                hashmap[nums[i]] = i
