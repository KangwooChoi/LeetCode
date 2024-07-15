# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        def dfs(node, p, q):
            nonlocal ans
            ret = [-1, -1]

            if node.left:
                l_ret = dfs(node.left, p, q)
                if l_ret[0] >= 0:
                    ret[0] = l_ret[0] + 1
                if l_ret[1] >= 0:
                    ret[1] = l_ret[1] + 1
            
            if node.right:
                r_ret = dfs(node.right, p, q)
                if r_ret[0] >= 0:
                    ret[0] = r_ret[0] + 1
                if r_ret[1] >= 0:
                    ret[1] = r_ret[1] + 1

            if node.val == p:
                ret[0] = 0
            if node.val == q:
                ret[1] = 0
            
            if ret[0] >= 0 and ret[1] >= 0:
                #print(node)
                ans = min(ans, ret[0] + ret[1])

            return ret
        ans = 1e9
        dfs(root, p, q)
        return ans