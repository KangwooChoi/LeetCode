# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        from collections import defaultdict
        in_degree = defaultdict(list)
        pos = -1
        if head:
            in_degree[head] = [1, 0]
        else:
            return False     
        pos = 0
        next = head.next
        while next:
            #print('next.val: ', next.val)
            pos += 1
            if next:
                if in_degree[next]:
                    pos = in_degree[next][1]
                    return True
                else:
                    in_degree[next] = [1, pos]
            next = next.next
        pos = -1
        return False
