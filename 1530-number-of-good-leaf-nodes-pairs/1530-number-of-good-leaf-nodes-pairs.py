# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _traverse_tree(self, curr_node, prev_node, graph, leaf_nodes):
        if curr_node is None:
            return
        if curr_node.left is None and curr_node.right is None:
            leaf_nodes.add(curr_node)
        if prev_node is not None:
            if prev_node not in graph:
                graph[prev_node] = []
            graph[prev_node].append(curr_node)

            if curr_node not in graph:
                graph[curr_node] = []
            graph[curr_node].append(prev_node)

        self._traverse_tree(curr_node.left, curr_node, graph, leaf_nodes)
        self._traverse_tree(curr_node.right, curr_node, graph, leaf_nodes)

    def countPairs(self, root, distance):
        graph = {}
        leaf_nodes = set()

        self._traverse_tree(root, None, graph, leaf_nodes)

        ans = 0

        for leaf in leaf_nodes:
            bfs_queue = []
            seen = set()
            bfs_queue.append(leaf)
            seen.add(leaf)
            for i in range(distance + 1):
                # Clear all nodes in the queue (distance i away from leaf node)
                # Add the nodes' neighbors (distance i+1 away from leaf node)
                size = len(bfs_queue)
                for j in range(size):
                    curr_node = bfs_queue.pop(0)
                    if curr_node in leaf_nodes and curr_node != leaf:
                        ans += 1
                    if curr_node in graph:
                        for neighbor in graph.get(curr_node):
                            if neighbor not in seen:
                                bfs_queue.append(neighbor)
                                seen.add(neighbor)
        return ans // 2
#class Solution:
#    def traverse_tree(self, node, prev, graph, leaves):
#        if node is None:
#            return
#        if node.left is None and node.right is None:
#            leaves.add(node)
#        if prev is not None:
#            if prev is not graph:
#                graph[prev] = []
#            graph[prev].append(node)
#        
#            if node not in graph:
#                graph[node] = []
#            graph[node].append(prev)
#        
#        self.traverse_tree(node.left, node, graph, leaves)
#        self.traverse_tree(node.right, node, graph, leaves)
#
#    def countPairs(self, root: TreeNode, distance: int) -> int:
#
#        graph = {}
#        leaves = set()
#
#        self.traverse_tree(root, None, graph, leaves)
#        #print(graph)
#        print(leaves)
#        
#        ans = 0
#
#        for leaf in leaves:
#            bfs_que = []
#            seen = set()
#            bfs_que.append(leaf)
#            seen.add(leaf)
#            for i in range(distance + 1):
#                size = len(bfs_que)
#                for j in range(size):
#                    now = bfs_que.pop(0)
#                    if now in leaves and now != leaf:
#                        ans += 1
#                    if now in graph:
#                        for neighbor in graph.get(now):
#                            if neighbor not in seen:
#                                bfs_que.append(neighbor)
#                                seen.add(neighbor)
#
#        return ans // 2