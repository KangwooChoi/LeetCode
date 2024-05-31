class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        counter = defaultdict(int)
        for num in nums:
            if counter[num]:
                del counter[num]
            else:
                counter[num] = 1
        return list(counter.keys())