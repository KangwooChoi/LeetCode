class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        def union(parents, x, y):
            x_p = find(parents, x) 
            y_p = find(parents, y) 
            if x_p < y_p:
                parents[y_p] = x_p
                find(parents, y)
            else:
                parents[x_p] = y_p
                find(parents, x)
        
        def find(parents, i):
            if i != parents[i]:
                parents[i] = find(parents, parents[i])
            return parents[i]

        def check(parents):
            if any(parents):
                return False
            else:
                return True

        parents = [i for i in range(n)]
        logs.sort(key=lambda x: x[0])

        grp_cnt = n
        for t, a, b in logs:
            if find(parents, a) != find(parents, b):
                union(parents, a, b)
                grp_cnt -= 1
                if grp_cnt == 1:
                    return t
        return -1