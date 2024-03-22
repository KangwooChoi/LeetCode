class Solution:
    def firstUniqChar(self, s: str) -> int:
        char_dict = dict()
        already_list = []
        for idx, c in enumerate(s):
            if c in already_list: 
                char_dict[c] = -1
            else:
                char_dict[c] = idx
                already_list.append(c)
        
        min_loc = 987654321
        for key, idx in char_dict.items():
            if idx != -1:
                if min_loc > idx:
                    min_loc = idx
        return min_loc if min_loc != 987654321 else -1

        
