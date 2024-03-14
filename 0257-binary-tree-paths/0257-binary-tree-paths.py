# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if not root:
            return []
        
        def dfs(node, s=''):
            if node is None:
                return
            if node.left is None and node.right is None:
                s += str(node.val)
                answer.append(s)
                return
            if node.val:
                s += f'{str(node.val)}->' 
            dfs(node.left, s)
            dfs(node.right, s)

        answer = []
        if root:
            dfs(root) 

        return answer
