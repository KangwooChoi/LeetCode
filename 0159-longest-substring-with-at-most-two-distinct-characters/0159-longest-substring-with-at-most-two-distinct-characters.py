class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        ans = 0
        index = 0
        loc = []
        chars = []
        while index < len(s):
            if s[index] not in chars:
                chars.append(s[index])
                loc.append(index)
            index += 1
            if len(loc) == 2:
                break

        if index >= len(s):
            return len(s)

        #print("chars: ", chars)
        #print("loc: ", loc)
        for i in range(index, len(s)):
            if s[i] not in chars:
                if ans < i - loc[0]:
                    ans = i - loc[0]
                if s[i-1] == chars[1]:
                    #print("here", s[i-1], loc[1])
                    k = i-1
                    while s[k] == s[i-1]:
                        k -= 1
                    chars[0] = chars[1]
                    chars[1] = s[i]
                    loc[0] = k+1
                    loc[1] = i
                else:
                    #print("there", s[i-1], loc[1])
                    k = i-1
                    while s[k] == s[i-1]:
                        k -= 1
                    loc[0] = k + 1
                    loc[1] = i
                    chars[1] = s[i]
                #print("chars: ", chars)
                #print("loc: ", loc)
        if s[-1] in chars:
            if len(s) - loc[0] > ans:
                return len(s) - loc[0]

        return ans