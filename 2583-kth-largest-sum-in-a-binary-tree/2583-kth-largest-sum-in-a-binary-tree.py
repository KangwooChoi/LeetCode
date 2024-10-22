# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        pq = []
        bfs_que = deque()
        bfs_que.append(root)

        while bfs_que:
            size = len(bfs_que)
            level_sum = 0
            for _ in range(size):
                node = bfs_que.popleft()
                level_sum += node.val
                if node.left:
                    bfs_que.append(node.left)
                if node.right:
                    bfs_que.append(node.right)

            heapq.heappush(pq, -level_sum)
        
        if len(pq) < k:
            return -1
        
        for _ in range(k - 1):
            heapq.heappop(pq)
        
        return -heapq.heappop(pq)
