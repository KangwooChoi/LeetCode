# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        slow, fast = head, head
        while fast:
            if fast.next:
                fast = fast.next.next 
            else:
                break
            prev = slow
            slow = slow.next
        #print(prev.val, slow.val)
        if slow:
            prev.next = slow.next
        else:
            prev.next = None
        return head