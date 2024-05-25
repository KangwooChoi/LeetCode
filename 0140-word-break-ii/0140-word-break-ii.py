class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        def backtrack(matched, remains):
            n = len(remains)
            for word in wordDict:
                match = copy.deepcopy(matched)
                m = len(word)
                if m <= n:
                    if word == remains[:m]:
                        match.append(word)
                        if m == n:
                            ans.append(' '.join(match))
                            return
                        else:
                            backtrack(match, remains[m:])
            return
        ans = []                     
        backtrack([], s)
        return ans
