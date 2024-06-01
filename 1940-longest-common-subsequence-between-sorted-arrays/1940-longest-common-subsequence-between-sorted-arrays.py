class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
        ans = []
        locs = [0] * len(arrays) 
        #comp = max([arrays[i][0] for i in range(len(arrays))])
        while True:
            comp = 0
            for i in range(len(arrays)):
                if locs[i] == len(arrays[i]):
                    return ans
                comp = max(comp, arrays[i][locs[i]])
            #print("comp: ", comp)
            cnt = 0
            for i in range(len(arrays)):
                if locs[i] == len(arrays[i]):
                    return ans
                while arrays[i][locs[i]] <= comp:
                    if arrays[i][locs[i]] == comp:
                        cnt += 1
                        locs[i] += 1
                        break
                    locs[i] += 1
                    if locs[i] == len(arrays[i]):
                        return ans
            #print("cnt: ", cnt)
            #print("loc: ", locs)
            if cnt == len(arrays):
                ans.append(comp)
            #print("ans: ", ans)