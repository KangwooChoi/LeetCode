class Solution:
    def longestPalindrome(self, s: str) -> int:
        from collections import Counter
        s_counter = Counter(s)
        ans = 0
        flg = False
        for key in s_counter.keys():
            if s_counter[key] % 2 == 0:
                ans += s_counter[key]
            else:
                flg = True
                if s_counter[key] > 2:
                    ans += s_counter[key] - 1
        return ans + 1 if flg == True else ans