class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False 
        from collections import Counter
        counter1 = Counter(word1)
        counter2 = Counter(word2)
        keys1 = sorted(counter1.keys())
        keys2 = sorted(counter2.keys())
        if len(keys1) != len(keys2):
            return False
        for i in range(len(keys1)):
            if keys1[i] != keys2[i]:
                return False
        cnt1 = sorted(counter1.values())
        cnt2 = sorted(counter2.values())
        for i in range(len(cnt1)):
            if cnt1[i] != cnt2[i]:
                return False
        return True