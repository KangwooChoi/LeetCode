# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        def dfs(now, prev):
            if not now.left and not now.right:      # leaf node 
                diff = now.val - 1
                prev.val += diff
                return abs(diff)
            left, right = 0, 0
            if now.left:
                left = dfs(now.left, now)
            if now.right:
                right = dfs(now.right, now)
            
            diff = now.val - 1
            prev.val += diff
            return left + right + abs(diff)
            
        left, right = 0, 0

        if root.left:
            left = dfs(root.left, root)
        if root.right:
            right = dfs(root.right, root)
        print("left, right: ", left, right)
        return left + right