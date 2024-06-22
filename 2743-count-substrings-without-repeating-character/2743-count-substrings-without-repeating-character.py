class Solution:
    def numberOfSpecialSubstrings(self, s: str) -> int:
        ans = 0
        start = 0
        freq = [0] * 26
        for end in range(len(s)): 
            freq[ord(s[end])-ord('a')] += 1

            while freq[ord(s[end]) - ord('a')] > 1:
                freq[ord(s[start]) - ord('a')] -= 1
                start += 1
            
            ans += end - start + 1

        return ans