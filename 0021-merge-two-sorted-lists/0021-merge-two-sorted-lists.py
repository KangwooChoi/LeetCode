# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1
        if list1.val <= list2.val:
            head = list1
            next1 = list1.next
            next2 = list2
        else:
            head = list2
            next1 = list1
            next2 = list2.next

        now = head
        #print(now.val)
        while next1 and next2:
            if next1.val <= next2.val:
                now.next = next1
                next1 = next1.next
            else:
                now.next = next2
                next2 = next2.next
            now = now.next
            #print(now)
        #print('next1: ', next1)
        #print('next2: ', next2)
        #print('now: ', now)
        if next1:
            now.next = next1
        if next2:
            now.next = next2
        
        return head