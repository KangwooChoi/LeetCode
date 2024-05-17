class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        n = min(len(word1), len(word2))
        ans = ''
        for i in range(n):
            ans += word1[i] + word2[i]
        if len(word1) > len(word2):
            ans += word1[n:] 
        elif len(word2) > len(word1):
            ans += word2[n:]
        return ans