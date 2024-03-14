# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        def dfs(node, prev):
            if not node:
                return prev
            next_node = node.next
            node.next = prev
            return dfs(next_node, node)
        return dfs(head, None)    