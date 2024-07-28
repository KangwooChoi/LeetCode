class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        g = [[] for _ in range(n + 1)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        q = deque([(1, 1)])
        dist1 = [-1] * (n + 1)
        dist2 = [-1] * (n + 1)
        dist1[1] = 0
        while q:
            x, freq = q.popleft()
            t = dist1[x] if freq == 1 else dist2[x]

            if (t // change) % 2:
                t = change * (t // change + 1) + time
            else:
                t += time
                
            for y in g[x]:
                if dist1[y] == -1:
                    dist1[y] = t
                    q.append((y, 1))
                elif dist2[y] == -1 and dist1[y] != t:
                    if y == n:
                        return t
                    dist2[y] = t
                    q.append((y, 2))
        return 0

        
#class Solution:
#    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
#        def calc(cnt, time, change):
#            ans = 0
#            for i in range(cnt):
#                if ans // change % 2 == 1:
#                    ans += change - (ans % change)
#                ans += time
#            return ans 
#        from collections import deque
#        graph = [[] for _ in range(n+1)]
#        for u, v in edges:
#            graph[u].append(v)
#            graph[v].append(u)
#        queue = deque()
#        queue.append((1,0))
#        cand = set()
#        while queue:
#            node, cnt = queue.popleft()
#            #print("node, cnt: ", node, cnt)
#            nexts = graph[node]
#            #print("nexts: ", nexts)
#            for next in nexts:
#                if next == n:
#                    cand.add(cnt+1)
#                    if len(cand) == 2:
#                        #print(cand)
#                        second_cnt = sorted(list(cand))[1]
#                        return calc(second_cnt, time, change)
#                queue.append((next, cnt + 1))
#        return -1