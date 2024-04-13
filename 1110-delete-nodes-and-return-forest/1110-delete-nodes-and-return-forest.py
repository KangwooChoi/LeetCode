# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        from collections import deque
        if not root:
            return []
        else:
            if root.val not in to_delete:
                forest = [root]
            elif root.val in to_delete:
                forest = []
                if root.left.val not in to_delete:
                    forest.append(root.left)
                if root.right.val not in to_delete:
                    forest.append(root.right)
                to_delete.remove(root.val)
        dq = deque()
        dq.append(root)
        while dq:
            now = dq.popleft()
            #print("now: ", now)
            if now.left:
                #print("now.left: ", now.left)
                dq.append(now.left)
                if now.left.val in to_delete:
                    if now.left.left and now.left.left.val not in to_delete:
                        #print("now.left.left: ", now.left.left)
                        forest.append(now.left.left)
                    if now.left.right and now.left.right.val not in to_delete:
                        #print("now.left.right: ", now.left.right)
                        forest.append(now.left.right)
                    to_delete.remove(now.left.val)
                    now.left = None
            if now.right:
                #print("now.right: ", now.right)
                dq.append(now.right)
                if now.right.val in to_delete:
                    if now.right.left and now.right.left.val not in to_delete:
                        #print("now.right.left: ", now.right.left)
                        forest.append(now.right.left)
                    if now.right.right and now.right.right.val not in to_delete:
                        #print("now.right.right: ", now.right.right)
                        forest.append(now.right.right)
                    to_delete.remove(now.right.val)
                    now.right = None
        return forest
                