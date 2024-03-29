class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        from collections import Counter
        counter = Counter(nums)
        for key in counter.keys():
            if counter[key] == 1:
                return key
        return None