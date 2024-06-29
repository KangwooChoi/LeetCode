class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        ans = [[] for _ in range(n)]
        directChild = [[] for _ in range(n)]
        for e in edges:
            directChild[e[0]].append(e[1])
        for i in range(n):
            self.dfs(i, i, ans, directChild)
        return ans

    def dfs(self, x: int, curr: int, ans: List[List[int]], directChild: List[List[int]]) -> None:
        for ch in directChild[curr]:
            if not ans[ch] or ans[ch][-1] != x:
                ans[ch].append(x)
                self.dfs(x, ch, ans, directChild)

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
            

        