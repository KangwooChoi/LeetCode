class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        from collections import Counter
        count = Counter(s)
        ans = 0
        for val in count.values():
            print(val)
            ans += val * (val+1) // 2
        return ans