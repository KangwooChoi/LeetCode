class Solution:
    def distanceToCycle(self, n, edges):
        # 'is_in_cycle' is initially True for all nodes
        is_in_cycle = [True] * n
        visited = [False] * n
        degree = [0] * n
        distances = [0] * n
        adjacency_list = [[] for _ in range(n)]

        # Build the adjacency list and calculate node degrees
        for edge in edges:
            adjacency_list[edge[0]].append(edge[1])
            adjacency_list[edge[1]].append(edge[0])
            degree[edge[0]] += 1
            degree[edge[1]] += 1

        node_queue = deque()

        # Start by adding all leaf nodes (degree 1) to the queue
        for i in range(n):
            if degree[i] == 1:
                node_queue.append(i)

        # Perform BFS to remove nodes with degree 1, progressively reducing the graph
        while node_queue:
            current_node = node_queue.popleft()
            # Mark the node as not in the cycle
            is_in_cycle[current_node] = False

            # Update the degree of neighbors and add them to the queue if their degree becomes 1
            for neighbor in adjacency_list[current_node]:
                degree[neighbor] -= 1
                if degree[neighbor] == 1:
                    node_queue.append(neighbor)

        # Add all cycle nodes to the queue and mark them as visited
        for current_node in range(n):
            if is_in_cycle[current_node]:
                node_queue.append(current_node)
                visited[current_node] = True

        # BFS to calculate distances from cycle nodes
        current_distance = 0
        while node_queue:
            # Track number of nodes to process at this distance level
            queue_size = len(node_queue)
            for _ in range(queue_size):
                current_node = node_queue.popleft()
                # Set the distance for the current node
                distances[current_node] = current_distance

                # Add unvisited neighbors to the queue
                for neighbor in adjacency_list[current_node]:
                    if visited[neighbor]:
                        continue
                    node_queue.append(neighbor)
                    visited[neighbor] = True
            # Increment distance after processing all nodes at the current level
            current_distance += 1

        return distances
#class Solution:
#    def distanceToCycle(self, n: int, edges: List[List[int]]) -> List[int]:
#        INF = int(1e9)
#        cost_arr = [INF] * n
#        visited = [False] * n
#        graph = [[] for _ in range(n)]
#        for s, e in edges:
#            graph[s].append(e)
#            graph[e].append(s)
#            if visited[s] == True and visited[e] == True:
#                # cycle
#            else:
#                visited[s] = True
#                visited[e] = True
#        queue = []
#        for start in cycle: