class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        s_cnter = Counter(s)
        t_cnter = Counter(t) 
        for key, cnt in s_cnter.items():
            if key not in t_cnter or t_cnter[key] != cnt:
                return False
        return True