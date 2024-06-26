# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        def inorder(node, array):
            # inorder traversal
            if node is None:
                return

            array.append(node.val)
            inorder(node.left, array)
            inorder(node.right, array)

            return

        def build(array):
            if len(array) == 0:
                return None

            left, right = 0, len(array) - 1
            mid = (left + right) // 2

            #print("len(array), mid: ", len(array), mid)  
            left_node = build(array[:mid]) 
            right_node = build(array[mid+1:]) 
            mid_node = TreeNode(array[mid], left_node, right_node)

            return mid_node

        inorder_list = []
        inorder(root, inorder_list)    
        inorder_list.sort()
        #print("inorder_list: ", inorder_list)

        return build(inorder_list)
        