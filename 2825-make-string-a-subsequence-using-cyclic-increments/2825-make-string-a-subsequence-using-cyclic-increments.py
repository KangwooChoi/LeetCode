class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        ptr2 = 0
        n = len(str2)
        for c in str1:
            if (c == str2[ptr2] 
               or ord(c) + 1 == ord(str2[ptr2])
               or (c == 'z' and str2[ptr2] == 'a')):
                ptr2 += 1
                if ptr2 == n:
                    return True
        return False 