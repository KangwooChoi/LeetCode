class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        counter = [[0]*26 for _ in range(len(words))]
        for i in range(len(words)):
            for c in words[i]:
                counter[i][ord(c)-ord('a')] += 1

        ans = []
        lower = 'abcdefghijklmnopqrstuvwxyz'
        for i in range(26):
            dup = 1e9
            for j in range(len(words)):
                dup = min(dup, counter[j][i])
            if dup !=0:
                ans += [lower[i]] * dup
        return ans