# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def preorder(node, p, q):
            if not node:
                return False, False 
            
            nonlocal ans

            l0, r0 = False, False
            if node == p:
                l0 = True
            elif node == q:
                r0 = True

            l1, r1 = preorder(node.left, p, q)
            l2, r2 = preorder(node.right, p, q)

            left = (l0 or l1 or l2)
            right = (r0 or r1 or r2)

            if left and right:
                ans.append(node)
            
            return left, right
        
        ans = []
        preorder(root, p, q)
        return ans[0]
