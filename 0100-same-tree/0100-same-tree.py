# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Editorial
        if not p and not q:
            return True
        
        if not q or not p:
            return False

        if p.val != q.val:
            return False

        return self.isSameTree(p.right, q.right) and self.isSameTree(p.left, q.left)

        # MySol.
        #if not p and not q:
        #    return True
#
        #if p and q:
        #    p_queue = [p]
        #    q_queue = [q]
        #else:
        #    return False
#
        #while p_queue and q_queue:
        #    x = p_queue.pop(0)
        #    y = q_queue.pop(0)
        #    if (x.val != y.val):
        #        return False
        #    if (not x.left and y.left) or (x.left and not y.left) or (not x.right and y.right) or (x.right and not y.right):
        #        return False
        #    if x.left:
        #        p_queue.append(x.left)
        #        q_queue.append(y.left)
        #    if x.right:
        #        p_queue.append(x.right)
        #        q_queue.append(y.right)
#
        ##print('p_queue: ', p_queue)
        ##print('q_queue: ', q_queue)
##
        ##print('p_queue is None: ', p_queue is None)
        ##print('not p_queue: ', not p_queue)
#
#
        #return True if (not p_queue) and (not q_queue) else False