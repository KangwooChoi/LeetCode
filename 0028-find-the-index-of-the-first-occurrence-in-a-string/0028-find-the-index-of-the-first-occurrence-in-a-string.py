class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        check = 0
        start = -1
        needle_length = len(needle) 
        index = 0
        while index < len(haystack):
            if haystack[index] == needle[check]:
                if check == 0:
                    start = index
                check += 1
                if check == needle_length:
                    return start
                index += 1
            else:
                if start != -1:
                    index = start + 1 
                else:
                    index += 1
                start = -1
                check = 0
        
        return -1

