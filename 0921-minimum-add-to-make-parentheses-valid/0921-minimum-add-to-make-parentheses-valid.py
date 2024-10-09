class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        ans = 0
        open_cnt = 0
        for c in s:
            if c == '(':
                open_cnt += 1
            elif c == ')':
                if open_cnt > 0:
                    open_cnt -= 1
                elif open_cnt == 0:
                    ans += 1
        return ans + open_cnt