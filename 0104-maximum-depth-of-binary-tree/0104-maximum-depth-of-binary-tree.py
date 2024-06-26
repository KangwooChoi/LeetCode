# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        else:
            return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
        #if not root:
        #    return 0
        #maximum_depth = 0
#
        #def dfs(node: Optional[TreeNode], depth):
        #    if not node:
        #        return depth
        #    depth += 1
        #    return max(dfs(node.left, depth), dfs(node.right, depth))
        #
        #return dfs(root, 0)
             