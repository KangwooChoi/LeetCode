class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s_list = s.split(' ')
        for i in range(len(s_list)-1, -1, -1):
            word = s_list[i]
            if word != '': 
                return len(word)
        return 0