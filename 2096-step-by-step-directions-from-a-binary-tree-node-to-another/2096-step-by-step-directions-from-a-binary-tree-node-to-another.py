# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        def find(node, val, route):
            if not node:
                return None
            
            if node.val == val:
                return route 
            
            if node.left:
                ret = find(node.left, val, route+'L')
                if ret:
                    return ret
        
            if node.right:
                ret = find(node.right, val, route+'R')
                if ret:
                    return ret
            return None

        s_route = find(root, startValue, '')
        d_route = find(root, destValue, '')
        n = min(len(s_route), len(d_route))
        ans = ''
        #print(s_route)
        #print(d_route)
        i = 0
        while s_route and d_route:
            if s_route[0] == d_route[0]:
                s_route = s_route[1:]
                d_route = d_route[1:]
            else:
                break

        #print(s_route)
        #print(d_route)
        ans += 'U' * len(s_route)
        #s_route = deque(s_route)
        #print(s_route)
        #while s_route:
        #    now = s_route.pop()
        #    if now == 'L' or now == 'R':
        #        ans += 'U'
        ans += d_route
        return ans