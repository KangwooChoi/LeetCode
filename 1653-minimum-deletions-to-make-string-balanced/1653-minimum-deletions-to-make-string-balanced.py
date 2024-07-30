class Solution:
    def minimumDeletions(self, s: str) -> int:
        ans, count = 0, 0
        for i in s:
            if i == 'b':
                count += 1
            elif count:
                ans += 1
                count -= 1
        return ans
        #n = len(s)
        #count_a = [0] * n
        #count_b = [0] * n
        ##b_count = 0 
        ##for i in range(n):
        ##    count_b[i] = b_count
        ##    if s[i] == 'b':
        ##        b_count += 1
#
        #a_count = 0
        #for i in range(n-1, -1, -1):
        #    count_a[i] = a_count
        #    if s[i] == 'a':
        #        a_count += 1
        #
        #b_count = 0
        #ans = n
        #for i in range(n):
        #    count_b[i] = b_count
        #    if s[i] == 'b':
        #        b_count += 1
        #    ans = min(ans, count_a[i] + count_b[i])
        #
        #return ans
        #a_cnt, b_cnt = 0, 0
        #ans = 0
        #left, right = 0, 0
        #flag = False
        #for i in range(len(s)):
        #    if s[i] == 'b':
        #        if a_cnt == 0:
        #            b_cnt += 1
        #        else:
        #            ans += min(a_cnt, b_cnt)
        #            a_cnt = 0
        #            b_cnt = 1
        #    elif s[i] == 'a':
        #        if b_cnt:
        #            a_cnt += 1
        #
        #return ans