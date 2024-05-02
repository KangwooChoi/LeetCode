class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        ans = ''
        for i, c in enumerate(word):
            if c == ch:
                ans = c + ans
                if len(ans) == len(word): 
                    return ans
                else:
                    return ans + word[i+1:]
            else:
                ans = c + ans
        return word