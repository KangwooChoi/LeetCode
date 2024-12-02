class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(' ') 
        ans = 1
        for word in words:
            if word.startswith(searchWord): 
                return ans
            ans += 1
        return -1 