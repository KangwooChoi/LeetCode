class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)
        if m >= n:
            p, q = str1, str2
        else:
            p, q = str2, str1
        m, n = len(p), len(q)

        k = min(m, n)
        while m % k != 0 or n % k != 0:
            k -= 1
            if k == 0:
                return ""
        for i in range(k, 0, -1):
            for j in range(0, n-i+1):
                div = q[j:j+k+1]
                l = len(div)
                if p == div * (m // l) and q == div * (n // l): 
                    return div
        return ""
