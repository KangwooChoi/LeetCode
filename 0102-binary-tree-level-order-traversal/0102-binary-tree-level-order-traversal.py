# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        from collections import deque
        dq = deque()
        if root:
            dq.append([root, 0])
        else:
            return []
        ans = []
        level_prev = 0
        temp = []
        while dq:
            now, level = dq.popleft()
            if level != level_prev:
                ans.append(temp) 
                level_prev = level
                temp = [now.val]
            else:
                temp.append(now.val)

            if now.left:
                dq.append([now.left, level+1])
            if now.right:
                dq.append([now.right, level+1])

        ans.append(temp)

        return ans