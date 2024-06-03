class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        t_loc = 0
        n = len(t)
        for c in s:
            if c == t[t_loc]:
                t_loc += 1
                if t_loc == n:
                    return 0
        return len(t) - t_loc