class Solution:
    def reverseWords(self, s: str) -> str:
        ans = '' 
        words = s.split(' ')
        print(words)
        for i in range(len(words)-1, -1, -1):
            if words[i] == '':
                continue
            ans += words[i] + ' '
        ans = ans.strip()
        return ans