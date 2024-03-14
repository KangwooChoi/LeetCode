# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    #def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
    #    if not root:
    #        return [] 
    #    if not (root.left or root.right):
    #        return [root]
    #    ans = []
    #    stack = []
    #    while node.left:
    #        stack.append(node.left)
    #        node = node.left
    #    ans = node.val
    #    
    #     
    #    
    #    while next.left:
    #        node = node.left
    #    

    def helper(self, node, res: list):
        # inorder inorderTraversal pre(current.left) - mid(current) - post(current.right)
        if node:
            if node.left:
                self.helper(node.left, res)
            res.append(node.val)
            if node.right:
                self.helper(node.right, res)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        if not (root.left or root.right):
            return [root.val] 
        ans = []
        if root.left:
            self.helper(root.left, ans) 
        ans.append(root.val)
        if root.right:
            self.helper(root.right, ans)

        return ans