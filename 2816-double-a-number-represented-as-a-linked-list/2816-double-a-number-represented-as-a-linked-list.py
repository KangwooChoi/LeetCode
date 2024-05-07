# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ans = ListNode()
        if 5 <= head.val <= 9:
            ans.val = 1
            ans.next = head
        else:
            ans = head
        head.val = (head.val * 2) % 10 
        if head.next:
            now = head.next
            prev = head

        while now:
            if 5 <= now.val <= 9:
                prev.val += 1
            now.val = (now.val * 2) % 10
            prev = now
            now = now.next

        return ans if ans else head
