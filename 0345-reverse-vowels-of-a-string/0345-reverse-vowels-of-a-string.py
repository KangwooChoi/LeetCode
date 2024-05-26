class Solution:
    def reverseVowels(self, s: str) -> str:
        loc = []
        char = []
        for i in range(len(s)):
            if s[i] in 'aeiouAEIOU':
                loc.append(i)
                char.append(s[i])
        ans = ''
        cnt = 0
        for i in range(len(s)):
            if cnt < len(loc) and i == loc[cnt]:
                ans += char[-1-cnt]
                cnt += 1
            else:
                ans += s[i]
        return ans