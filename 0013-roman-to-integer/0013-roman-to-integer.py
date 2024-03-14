class Solution:
    def romanToInt(self, s: str) -> int:
        from collections import defaultdict
        roman_to_num = defaultdict()
        roman_to_num['I'] = 1
        roman_to_num['V'] = 5
        roman_to_num['X'] = 10
        roman_to_num['L'] = 50
        roman_to_num['C'] = 100
        roman_to_num['D'] = 500
        roman_to_num['M'] = 1000
        ans = 0
        for i in range(len(s)-1):
            if roman_to_num[s[i]] >= roman_to_num[s[i+1]]:
                ans += roman_to_num[s[i]]
            else:
                ans -= roman_to_num[s[i]]
        ans += roman_to_num[s[-1]]
        return ans