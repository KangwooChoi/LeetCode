class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        pattern_dict = defaultdict(str)
        s_list = s.split(' ')
        if len(pattern) != len(s_list):
            return False
        for i in range(len(pattern)):
            if pattern_dict[pattern[i]]:
                if pattern_dict[pattern[i]] != s_list[i]:
                    return False
            else:
                if s_list[i] in pattern_dict.values():
                    return False
                pattern_dict[pattern[i]] = s_list[i]
        return True
        