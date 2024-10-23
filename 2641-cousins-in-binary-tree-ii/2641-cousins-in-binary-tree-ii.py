# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(node, arr, depth):
            if not node:
                return
            if node.val:
                arr[depth] += node.val
            if node.left:
                dfs(node.left, arr, depth + 1) 
            if node.right:
                dfs(node.right, arr, depth + 1) 
            return

        def dfs2(node, arr, depth):
            if not node:
                return
            if not node.left and not node.right:
                return
            cousins = arr[depth + 1]
            if node.left:
                cousins -= node.left.val
            if node.right:
                cousins -= node.right.val
            if node.left:
                node.left.val = cousins 
                dfs2(node.left, arr, depth + 1)
            if node.right:
                node.right.val = cousins 
                dfs2(node.right, arr, depth + 1)
            return 

        arr = [0] * 100000
        dfs(root, arr, 0)
        #print(arr)
        root.val = 0
        dfs2(root, arr, 0) 
        return root
