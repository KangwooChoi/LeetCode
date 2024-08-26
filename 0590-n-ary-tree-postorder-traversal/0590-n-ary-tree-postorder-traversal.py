"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def helper(self, node: 'Node', arr: List[int]):
        if node is None:
            return
        if node.children:
            for child in node.children:
                self.helper(child, arr)
        arr.append(node.val)
        return 

    def postorder(self, root: 'Node') -> List[int]:
        ans = []
        self.helper(root, ans)
        return ans