# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None or head.next.next is None:
            return head
        even_root = ListNode(head.next.val)
        even_last = even_root
        head.next = head.next.next
        next = head.next
        prev = next
        while next:
            even_last.next = next.next
            even_last = even_last.next
            if next.next:
                next.next = next.next.next
            prev = next
            next = next.next
        prev.next = even_root
        return head

