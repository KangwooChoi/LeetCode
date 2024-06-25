# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def postorder(node, sum_val):
            if node is None:
                return
            if node.right:
                postorder(node.right, sum_val)
            sum_val[0] += node.val
            node.val = sum_val[0]
            if node.left:
                postorder(node.left, sum_val) 
        sum_val = [0]
        postorder(root, sum_val)
        return root