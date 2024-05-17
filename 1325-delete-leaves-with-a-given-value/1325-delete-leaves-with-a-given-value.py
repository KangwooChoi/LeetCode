# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        def dfs(node):
            if node.left:
                left = dfs(node.left) 
                if left == True:
                    node.left = None
            if node.right:
                right = dfs(node.right)
                if right == True:
                    node.right = None
            if node.val == target:
                if not node.left and not node.right:
                    return True
        if dfs(root) == True:
            return
        return root