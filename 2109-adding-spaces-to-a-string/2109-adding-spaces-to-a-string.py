class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = ''
        prev = 0
        for curr in spaces:
            ans += s[prev:curr] + ' ' 
            prev = curr
        ans += s[curr:]
        return ans