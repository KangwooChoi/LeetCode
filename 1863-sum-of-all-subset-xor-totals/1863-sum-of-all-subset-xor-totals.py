class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        from itertools import combinations
        ans = 0
        combos = []
        for i in range(1, len(nums)+1):
            combos += combinations(nums, i)
        print(combos)
        for combo in combos:
            base = combo[0]
            for x in combo[1:]:
                base ^= x
            ans += base
        return ans