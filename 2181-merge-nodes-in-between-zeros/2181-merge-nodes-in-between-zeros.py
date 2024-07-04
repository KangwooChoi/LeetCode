# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        now = head
        while now.val != 0:
            now = now.next
        ans = now
        next = now.next
        now.next = None
        while next:
            if next.val == 0:
                if next.next:
                    now.next = next.next
                    now = now.next
                    if now.next:
                        next = now.next
                    else:
                        break
                else:
                    now.next = None 
                    break
            else:
                now.val += next.val
                next = next.next
        return ans 