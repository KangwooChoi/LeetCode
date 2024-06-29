class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        graph = defaultdict(dict)
        for s, e in connections:
            graph[s][e] = 1
            graph[e][s] = 0
        
        queue = deque([0])
        ans = 0
        visited = [False] * n
        visited[0] = True

        while queue:
            now = queue.popleft()
            for nei, score in graph[now].items():
                if not visited[nei]:
                    ans += score
                    queue.append(nei)
                    visited[nei] = True
        
        return ans