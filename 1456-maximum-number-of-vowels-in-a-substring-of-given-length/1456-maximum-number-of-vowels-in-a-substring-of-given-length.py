class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        n = len(s)
        cnt = 0
        for i in range(k):
            if s[i] in 'aeiou':
                cnt += 1
        ans = cnt
        for i in range(k,n): 
            if s[i-k] in 'aeiou':
                cnt -= 1
            if s[i] in 'aeiou':
                cnt += 1
            ans = max(ans, cnt)
        return ans
