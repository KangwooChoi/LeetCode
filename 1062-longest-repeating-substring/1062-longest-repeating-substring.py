class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        all_subs = defaultdict(int)  
        n = len(s)
        for i in range(n):
            for j in range(i+1, n+1):
                sub = s[i:j]
                if sub not in all_subs:
                    all_subs[sub] = 1
                else:
                    all_subs[sub] += 1
        
        ans = 0
        for key in all_subs:
            if all_subs[key] >= 2:
                ans = max(ans, len(key))
        
        return ans