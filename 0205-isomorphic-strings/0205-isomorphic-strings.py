class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        from collections import defaultdict, Counter
        st_dict = defaultdict(str)
        for i in range(len(s)):
            if st_dict[s[i]]:
                if st_dict[s[i]] != t[i]:
                    return False
            else:
                st_dict[s[i]] = t[i]
        dup_check = [] 
        for key in st_dict:
            if st_dict[key] in dup_check:
                return False
            else:
                dup_check.append(st_dict[key])

        return True