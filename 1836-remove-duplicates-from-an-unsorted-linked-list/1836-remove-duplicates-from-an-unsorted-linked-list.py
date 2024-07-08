# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        dup_check = defaultdict(int)
        now = head
        while now:
            if now.val not in dup_check:
                dup_check[now.val] = 1
            else:
                dup_check[now.val] += 1
            now = now.next
        #print(dup_check)

        now = head
        start = None
        while now:
            if dup_check[now.val] == 1:
                start = now
                break
            now = now.next
        if not start:
            return None

        #print(start)
        next = start.next
        prev = start
        prev.next = None
        while next:
            if dup_check[next.val] == 1:
                prev.next = next
                prev = next
                prev.next = None
            next = next.next
        #print(prev)
        return start       



        

