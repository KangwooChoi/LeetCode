class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        length = len(s)
        suffixes = []

        for i in range(length):
            suffixes.append(s[i:])
        suffixes.sort()

        max_length = 0
        for i in range(1, length):
            cand = 0
            while (
                cand < min(len(suffixes[i]), len(suffixes[i-1]))
                and suffixes[i][cand] == suffixes[i-1][cand]
            ):
                cand += 1
            
            max_length = max(max_length, cand)
        return max_length

        #max_length = len(s) - 1
#
        #while max_length > 0:
        #    seen_subs = defaultdict(int)
        #    for start in range(len(s) - max_length + 1):
        #        end = start
        #        curr_sub = s[end:end + max_length]
        #        if curr_sub in seen_subs:
        #            return max_length
        #        seen_subs[curr_sub] = 1
        #    max_length -= 1
        #return 0
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