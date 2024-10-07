class Solution:
    def minLength(self, s: str) -> int:
        cnt = 1
        while cnt:
            cnt = 0
            cnt += s.count('AB')
            s = s.replace('AB', '')
            cnt += s.count('CD')
            s = s.replace('CD', '')
        return len(s)