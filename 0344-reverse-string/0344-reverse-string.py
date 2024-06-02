class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        #s = s[::-1]
        #reversed(s)
        s.reverse()
        #print(s)
        #mid = len(s) // 2
        #for i in range(mid):
        #    tail = -1*(i+1)
        #    temp = s[tail]
        #    s[tail] = s[i]
        #    s[i] = temp
        