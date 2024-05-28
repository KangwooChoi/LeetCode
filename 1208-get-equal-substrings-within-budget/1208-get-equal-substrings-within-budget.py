class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        diff = []
        for i in range(len(s)):
            diff.append(abs(ord(s[i])-ord(t[i])))
        print(diff)
        prev = 0
        ans = 0
        window = 0
        conti = 0
        for i in range(len(s)):
            window += diff[i]
            conti += 1
            if window <= maxCost:
                ans = max(ans, conti)
            else:
                while window > maxCost:
                    window -= diff[prev]
                    prev += 1
                    conti -= 1
        return ans