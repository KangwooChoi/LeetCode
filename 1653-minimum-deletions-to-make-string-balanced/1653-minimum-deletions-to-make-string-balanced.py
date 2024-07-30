class Solution:
    def minimumDeletions(self, s: str) -> int:
        a_cnt, b_cnt = 0, 0
        ans = 0
        left, right = 0, 0
        flag = False
        for i in range(len(s)):
            if s[i] == 'b':
                if a_cnt == 0:
                    b_cnt += 1
                else:
                    ans += min(a_cnt, b_cnt)
                    a_cnt = 0
                    b_cnt = 1
            elif s[i] == 'a':
                if b_cnt:
                    a_cnt += 1
        
        return ans