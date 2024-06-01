class Solution:
    def scoreOfString(self, s: str) -> int:
        ans = 0
        for  i in range(len(s)-1):
            ans += max(ord(s[i])-ord(s[i+1]), ord(s[i+1])-ord(s[i]))
        return ans