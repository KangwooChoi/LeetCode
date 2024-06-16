# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        def DFS(node, dir, k):
            if node.left is None and node.right is None:
                return k
            ret = [k]
            if node.left:
                if dir == 1:
                    ret.append(DFS(node.left, 0, k+1))
                else:
                    ret.append(DFS(node.left, 0, 1))
            if node.right:
                if dir == 0:
                    ret.append(DFS(node.right, 1, k+1))
                else:
                    ret.append(DFS(node.right, 1, 1))
            return max(ret)
        if root.left is None and root.right is None:
            return 0
        ret = []
        if root.left:
            ret.append(DFS(root.left, 0, 1))
        if root.right:
            ret.append(DFS(root.right, 1, 1))
        return max(ret)
             