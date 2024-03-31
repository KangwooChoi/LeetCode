# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        def DFS(node: TreeNode):
            if not node.left and not node.right:
                ans = 0
                ans += 1
                #print("ans: ", ans)
                return node.val, 1, ans
            l_sum = r_sum = l_cnt = r_cnt = l_ans = r_ans = 0
            if node.left:
                l_sum, l_cnt, l_ans = DFS(node.left)
            if node.right:
                r_sum, r_cnt, r_ans = DFS(node.right)
            ans = l_ans + r_ans
            if (l_sum+r_sum+node.val)//(l_cnt+r_cnt+1) == node.val:
                ans += 1
                #print("ans: ", ans)
            return l_sum+r_sum+node.val, l_cnt+r_cnt+1, ans
        
        return DFS(root)[2]