class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        seen_subs = set()
        max_length = len(s) - 1

        while max_length > 0:
            seen_subs.clear()
            for start in range(len(s) - max_length + 1):
                end = start
                curr_sub = s[end:end + max_length]
                if curr_sub in seen_subs:
                    return max_length
                seen_subs.add(curr_sub)
            max_length -= 1
        return 0
        #all_subs = defaultdict(int)  
        #n = len(s)
        #for i in range(n):
        #    for j in range(i+1, n+1):
        #        sub = s[i:j]
        #        if sub not in all_subs:
        #            all_subs[sub] = 1
        #        else:
        #            all_subs[sub] += 1
        #
        #ans = 0
        #for key in all_subs:
        #    if all_subs[key] >= 2:
        #        ans = max(ans, len(key))
        #
        #return ans