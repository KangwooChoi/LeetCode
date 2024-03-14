# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def countNodes(node: ListNode) -> int:
            cnt = 0
            while node:
                cnt += 1
                node = node.next
            return cnt
        
        middle = countNodes(head)//2
        cnt = 0
        node = head
        while node:
            if cnt == middle:
                return node
            cnt += 1
            node = node.next
        

