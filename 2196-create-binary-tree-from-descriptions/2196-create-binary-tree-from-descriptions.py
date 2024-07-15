# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        def helper(val, rel):
            node = TreeNode(val)
            left, right = rel[val][1], rel[val][2]
            if left:
                node.left = helper(left, rel)
            if right:
                node.right = helper(right, rel)
            return node

        rel_dict = defaultdict(list)
        for p, c, l in descriptions:
            if p not in rel_dict:
                rel_dict[p] = [None, c, None] if l else [None, None, c]
            else:
                if l:
                    rel_dict[p][1] = c
                else:
                    rel_dict[p][2] = c
            if c not in rel_dict:
                rel_dict[c] = [p, None, None]
            else:
                rel_dict[c][0] = p

        for key in rel_dict:
            if rel_dict[key][0] is None:
                root = key
                break

        return helper(root, rel_dict)