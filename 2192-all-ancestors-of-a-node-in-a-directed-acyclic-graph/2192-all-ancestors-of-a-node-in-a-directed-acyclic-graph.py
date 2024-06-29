class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        direct_p = [[] for _ in range(n)]
        for s, e in edges:
            direct_p[e].append(s)
        
        ans = []

        for i in range(n):
            ancestors = []
            visited = set()
            self.find_children(i, direct_p, visited)
            for node in range(n):
                if node == i:
                    continue
                if node in visited:
                    ancestors.append(node)
            ans.append(ancestors)

        return ans
    
    def find_children(self, curr, p, v):
        v.add(curr)
        for neighbour in p[curr]:
            if neighbour not in v:
                self.find_children(neighbour, p, v)



        #direct_p = [[] for _ in range(n)] 
        #ans = [[] for _ in range(n)] 
        #for s, e in edges:
        #    direct_p[e].append(s)
        #for i in range(len(direct_p)):
        #    q = copy.deepcopy(direct_p[i])
        #    while q:
        #        now = q.pop()
        #        ans[i].append(now)
        #        for new in direct_p[now]:
        #            if new not in q:
        #                q.append(new)
        #for i in range(len(ans)): 
        #    ans[i] = list(set(ans[i]))
        #    ans[i].sort()
        #return ans
            

        