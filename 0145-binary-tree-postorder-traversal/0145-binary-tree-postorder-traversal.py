# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def helper(node, arr):
            if not node:
                return
            if node.left:
                helper(node.left, arr) 
            if node.right:
                helper(node.right, arr)
            if node.val:
                ans.append(node.val)
            return
        
        ans = []
        helper(root, ans)

        return ans