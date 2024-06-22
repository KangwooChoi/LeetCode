class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        odd_indices = []
        ans = 0
        last_popped = -1
        initial_gap = -1

        for i in range(len(nums)):
            if nums[i] % 2 == 1:
                odd_indices.append(i)
            if len(odd_indices) > k:
                last_popped = odd_indices[0]
                odd_indices.pop(0)
            if len(odd_indices) == k:
                initial_gap = odd_indices[0] - last_popped
                ans += initial_gap
        
        return ans