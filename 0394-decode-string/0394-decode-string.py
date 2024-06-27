class Solution:
    def decodeString(self, s: str) -> str:
        from collections import deque
        def decode(s: deque):
            ans = ''
            while s:
                c = s.popleft()
                if c == ']':
                    return ans
                elif c == '[':
                    ret = decode(s)
                    ans += ret*mul
                elif c in '1234567890':
                    mul = int(c) 
                else:
                    ans += c
            return ans
        s = deque(s)
        return decode(s)
                