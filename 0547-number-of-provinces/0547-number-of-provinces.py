class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def union(i, j):
            p_i = parents[i]
            p_j = parents[j]
            if p_i != p_j:
                for k in range(0, n):
                    if parents[k] == p_j:
                        parents[k] = p_i

        def find(k):
            pass
            
        n = len(isConnected)
        parents = [i for i in range(n)]
        for i in range(n):
            for j in range(i+1, n):
                if isConnected[i][j]:
                    union(i,j)

        #print(parents)
        return len(set(parents))