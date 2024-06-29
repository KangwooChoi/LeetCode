class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        from collections import Counter
        rCnter = Counter(ransomNote)
        mCnter = Counter(magazine)
        for key, cnt in rCnter.items():
            if key not in mCnter or mCnter[key] < cnt:
                return False
        return True
        #rDict = defaultdict(str)
        #mDict = defaultdict(str)
        #for c in ransomNote:
        #    if rDict[c]:
        #        rDict[c] += 1
        #    else:
        #        rDict[c] = 1
#
        #for c in magazine:
        #    if mDict[c]:
        #        mDict[c] += 1
        #    else:
        #        mDict[c] = 1
        #
        #for key, cnt in rDict.items():
        #    if not mDict[key] or mDict[key] < cnt:
        #        return False
        #return True
                   