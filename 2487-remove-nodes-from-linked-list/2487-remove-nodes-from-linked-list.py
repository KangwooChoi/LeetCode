# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head.next:
            return head
        stack = [head]
        now = head.next
        while now and stack:
            #print(now.val, stack[-1].val)
            if now.val > stack[-1].val:
                stack.pop()
            else:
                stack[-1].next = now
                stack.append(now)
                now = now.next
            if not stack:
                stack = [now]
                now = now.next
        return stack[0]
