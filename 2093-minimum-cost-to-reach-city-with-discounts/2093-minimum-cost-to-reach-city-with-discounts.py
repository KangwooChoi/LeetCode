class Solution:
    def minimumCost(self, n: int, highways: List[List[int]], discounts: int) -> int: 
        # Solutions by user

        pq = [(0, 0, discounts)]
        graph = collections.defaultdict(list)
        visited = dict()
        cost = dict()

        for a, b, dist in highways:
            graph[a].append(b)
            graph[b].append(a)
            cost[(a,b)] = dist
            cost[(b,a)] = dist
        
        while pq:
            curr_cost, node, curr_disc = heapq.heappop(pq)
            if node in visited and curr_disc <= visited[node]:
                continue
            visited[node] = curr_disc
            if node == n - 1:
                return curr_cost
            for neigh in graph[node]:
                if curr_disc > 0:
                    heapq.heappush(pq, (cost[(node, neigh)] // 2 + curr_cost, neigh, curr_disc - 1))
                heapq.heappush(pq, (cost[(node, neigh)] + curr_cost, neigh, curr_disc))
                
        return -1


        # Editorial

        #graph = [[] for _ in range(n)]
        #for highway in highways:
        #    u, v, toll = highway
        #    graph[u].append((v, toll))
        #    graph[v].append((u, toll))
#
        #pq = [(0, 0, 0)]
#
        #dist = [[float("inf")] * (discounts + 1) for _ in range(n)]
        #dist[0][0] = 0
        #print(dist)
#
        #visited = [[False] * (discounts + 1) for _ in range(n)]
        #print(visited)
#
        #while pq:
        #    curr_cost, city, discount_used = heapq.heappop(pq)
        #    if visited[city][discount_used]:
        #        continue
        #    visited[city][discount_used] = curr_cost + toll
        #    
        #    for neighbor, toll in graph[city]:
        #        if curr_cost + toll < dist[neighbor][discount_used]:
        #            dist[neighbor][discount_used] = curr_cost + toll
        #            heapq.heappush(
        #                pq,
        #                (
        #                    dist[neighbor][discount_used],
        #                    neighbor,
        #                    discount_used
        #                )
        #            )
        #        
        #        if discount_used < discounts:
        #            new_cost_with_discount = curr_cost + toll // 2
        #            if new_cost_with_discount < dist[neighbor][discount_used + 1]:
        #                dist[neighbor][discount_used+1] = new_cost_with_discount
        #                heapq.heappush(
        #                    pq,
        #                    (
        #                        new_cost_with_discount,
        #                        neighbor,
        #                        discount_used + 1,
        #                    ),
        #                )
        #min_cost = min(dist[n-1])
        #return -1 if min_cost == float("inf") else min_cost
                        
#class Solution:
#    def minimumCost(self, n: int, highways: List[List[int]], discounts: int) -> int:
#        def DFS(node, adj, route, visited):
#            nonlocal candidates
#            visited = copy.deepcopy(visited)
#            route = copy.deepcopy(route)
#            visited[node] = True
#            queue = deque([])
#            for i, cost in enumerate(adj[node]):
#                if cost != -1:
#                    #print("Highway exists")
#                    if i == (n - 1):
#                        #print("HIT!!!")
#                        route.append(cost)
#                        candidates.append(route)
#                        continue
#                    if i != node and not visited[i]:
#                        #print("next node: ", i)
#                        route.append(cost)
#                        DFS(i, adj, route, visited)
#                        route.pop()
#
#        def helper(candidates, discounts):
#            if not candidates:
#                return -1
#
#            ans = 0
#            for cand in candidates:
#                cand.sort(reverse=True)
#                for i in range(min(discounts, len(cand))):
#                    cand[i] //= 2
#                new_cand = sum(cand)
#                ans = min(ans, new_cand)
#            return ans
#        
#        visited = [False] * n
#        adj = [[-1] * n for _ in range(n)]
#        for s, d, c in highways:
#            adj[s][d] = c
#            adj[d][s] = c
#        #print(adj)
#        candidates = []
#        route = []
#        DFS(0, adj, route, visited)
#        #print(candidates) 
#        return helper(candidates, discounts)