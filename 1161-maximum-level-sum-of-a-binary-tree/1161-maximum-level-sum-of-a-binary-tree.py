# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        from collections import deque
        def BFS(queue, k):
            k_sum = 0
            next = []
            while queue:
                node = queue.pop()
                k_sum += node.val
                if node.left:
                    next.append(node.left)
                if node.right:
                    next.append(node.right)
            if next:
                index, maximum = BFS(next, k+1)
                if maximum > k_sum:
                    return index, maximum
            return k, k_sum
        return BFS([root], 1)[0]


