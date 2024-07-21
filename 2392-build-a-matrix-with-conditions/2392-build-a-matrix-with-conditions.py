class Solution:
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        ans = [[0] * k for _ in range(k)]
        row_graph = dict()
        col_graph = dict()
        row_indegree = [0] * (k+1)
        col_indegree = [0] * (k+1)
        for first, second in rowConditions:
            if first not in row_graph:
                row_graph[first] = [second]
                row_indegree[second] += 1
            else:
                row_graph[first].append(second)
                row_indegree[second] += 1
        for first, second in colConditions:
            if first not in col_graph:
                col_graph[first] = [second]
                col_indegree[second] += 1
            else:
                col_graph[first].append(second)
                col_indegree[second] += 1
        total = set([i for i in range(1, k+1)])
        row_children = total - set(row_graph.keys())
        col_children = total - set(col_graph.keys())
        print(row_children)
        print(col_children)
        if not row_children or not col_children:
            return []
        row_order = []
        col_order = []
        visited = [False] * (k+1)
        limit = 0
        while row_graph:
            print("row_graph: ", row_graph)
            limit += 1
            if limit > 10:
                break
            for i in range(1, len(row_indegree)):
                if row_indegree[i] == 0 and visited[i] == False:
                    row_order.append(i)
                    visited[i] = True
                    if i in row_graph:
                        for child in row_graph[i]:
                            row_indegree[child] -= 1
                        del row_graph[i]
                        if row_indegree[child] == 0:
                            row_order.append(child)
                            visited[child] = True
                    break
            
        visited = [False] * (k+1)
        limit = 0
        while col_graph:
            print("col_graph: ", col_graph)
            limit += 1
            if limit > 10:
                break
            for i in range(1, len(row_indegree)):
                if col_indegree[i] == 0 and visited[i] == False:
                    col_order.append(i)
                    visited[i] = True
                    if i in col_graph:
                        for child in col_graph[i]:
                            col_indegree[child] -= 1
                        del col_graph[i]
                        if not col_graph and col_indegree[child] == 0:
                            col_order.append(child)
                            visited[child] = True
                    break
        print("row_order: ", row_order)
        print("col_order: ", col_order)

        from collections import deque
        queue = deque(row_order)
        r = 0
        while queue:
            now = queue.popleft()
            index = 0
            for i, col in enumerate(col_order):
                if col == now:
                    index = i
                    break
            ans[r][i] = now
            r += 1
        return ans