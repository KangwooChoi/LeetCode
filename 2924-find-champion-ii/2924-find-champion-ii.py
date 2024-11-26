class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        stronger = [[] for _ in range(n)]
        for st, we in edges:
            stronger[we].append(st)
        
        ans = -1
        for i in range(n):
            if len(stronger[i]) == 0:
                if ans == -1:
                    ans = i
                else:
                    return -1
        return ans