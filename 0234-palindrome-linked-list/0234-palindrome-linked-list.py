# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        #### using list[::-1]  
        if not head:
            return True
        val_list = []
        while head:
            val_list.append(head.val)
            head = head.next
        return val_list == val_list[::-1]


        #### using deque
        #if not head:
        #    return True
        #from collections import deque
        #q = deque([head.val])
        #while head.next:
        #    q.append(head.next.val)
        #    head = head.next
        #flag = True
        #while flag and len(q) >= 2:
        #    if q.popleft() != q.pop():
        #        return False
        #return True
