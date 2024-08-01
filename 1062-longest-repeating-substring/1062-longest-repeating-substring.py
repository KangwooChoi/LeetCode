class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        start, end = 0, len(s)
        while start <= end:
            mid = (start + end) // 2
            if self._has_repeating(s, mid):
                start = mid + 1
            else:
                end = mid - 1
        return start - 1

    
    def _has_repeating(self, s:str, length: int) -> bool:
        seen_subs = set()
        for i in range(len(s) - length + 1):
            sub = s[i:i+length]
            if sub in seen_subs:
                return True
            seen_subs.add(sub)
        return False

        
        #length = len(s)
        #suffixes = []
#
        #for i in range(length):
        #    suffixes.append(s[i:])
        #suffixes.sort()
        ##print(suffixes)
#
        #max_length = 0
        #for i in range(1, length):
        #    cand = 0
        #    while (
        #        cand < min(len(suffixes[i]), len(suffixes[i-1]))
        #        and suffixes[i][cand] == suffixes[i-1][cand]
        #    ):
        #        cand += 1
        #    
        #    max_length = max(max_length, cand)
        #return max_length

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