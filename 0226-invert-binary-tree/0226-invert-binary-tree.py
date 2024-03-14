# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        
        from collections import deque
        q = deque()
        q.append(root)
        #visited = [0 for _ in range(0, 101)]
        while q:
            now = q.popleft()
            #if visited[now.val] == 0:
            if now.left:
                q.append(now.left)
            if now.right:
                q.append(now.right)
            now.left, now.right = now.right, now.left
            #visited[now.val] = 1
        return root

