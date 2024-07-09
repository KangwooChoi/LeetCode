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

            left, right = False, False
            if node == p:
                left = True
            elif node == q:
                right = True

            l1, r1 = preorder(node.left, p, q)
            l2, r2 = preorder(node.right, p, q)

            if (left or l1 or l2) and (right or r1 or r2):
                ans.append(node)
            
            return (left or l1 or l2), (right or r1 or r2)
        
        ans = []
        preorder(root, p, q)
        return ans[0]
