# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        
        def dfs(node, height = 0):
            if not node:
                return 0
            left_h = dfs(node.left, height)
            right_h = dfs(node.right, height)
            #if left_h - right_h > 1 or right_h - left_h > 1:
            if abs(left_h - right_h) > 1:
                ans.append(False)
            return max(left_h, right_h) + 1 
        
        ans = [True]
        
        dfs(root, 0)

        return True if all(ans) else False

        ## balanced --> depth diff <= 1
        #def dfs(node, depth):
        #    if node is None:
        #        depth_list.append(depth)
        #        return
        #    depth += 1
        #    dfs(node.left, depth)
        #    dfs(node.right, depth)
        #    return
        #if not root:
        #    return True
        #depth_list = []
        #dfs(root, 0)
        #print('depth_list: ', depth_list)
        #print('max(depth_list): ', max(depth_list))
        #print('min(depth_list): ', min(depth_list))
        #return True if (max(depth_list) - min(depth_list)) <= 2 else False
