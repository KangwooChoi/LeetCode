# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def DFS(node, maximum):
            ret = 0
            if node.left:
                ret += DFS(node.left, max(maximum, node.val)) 
            if node.right:
                ret += DFS(node.right, max(maximum, node.val)) 
            if maximum <= node.val:
                ret += 1
            return ret
        return DFS(root, -10**4)
            