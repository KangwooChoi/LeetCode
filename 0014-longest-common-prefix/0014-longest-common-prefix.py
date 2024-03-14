class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]
        common_prefix = strs[0]
        for word in strs[1:]:
            new_common = ''
            for i in range(min(len(common_prefix), len(word))):
                if common_prefix[i] == word[i]:
                    new_common += word[i]
                else:
                    break
            common_prefix = new_common
        return common_prefix
