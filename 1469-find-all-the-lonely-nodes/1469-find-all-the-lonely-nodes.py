# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(node):
            if not node.left and not node.right:
                return
            elif node.left and not node.right:
                ans.append(node.left.val)
                dfs(node.left)
                return
            elif node.right and not node.left:
                ans.append(node.right.val)
                dfs(node.right)
                return
            else:
                dfs(node.left)
                dfs(node.right)
                return 

        ans = []
        dfs(root)
        return ans
         