class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        INF = 1e9
        adj = [[INF] * n for _ in range(n)]
        for s, e, c in edges:
            if c <= distanceThreshold:
                adj[s][e] = c
                adj[e][s] = c
        
        #
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if i == j:
                        continue
                    new_cost = adj[i][k] + adj[k][j]
                    if new_cost <= distanceThreshold and new_cost < adj[i][j]:
                        adj[i][j] = new_cost

        #print(adj) 

        counter = [0] * n 
        for i, row in enumerate(adj):
            #print(row)
            for c in row:
                #print(c)
                if c <= distanceThreshold:
                    counter[i] += 1
            #print(counter[i])
        #print(counter)
        minimum = 1e9
        index = -1
        for i, cnt in enumerate(counter):
            if cnt <= minimum:
                minimum = cnt
                index = i 
        return index