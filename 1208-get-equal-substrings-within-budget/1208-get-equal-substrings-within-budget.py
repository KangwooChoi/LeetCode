class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        diff = []
        for i in range(len(s)):
            diff.append(max(ord(s[i])-ord(t[i]), ord(t[i])-ord(s[i])))
        print(diff)
        prev = 0
        ans = 0
        window = 0
        conti = 0
        for i in range(len(s)):
            window += diff[i]
            if window <= maxCost:
                conti += 1
                ans = max(ans, conti)
            else:
                window -= diff[prev]
                prev += 1
                conti -= 1
        return ans