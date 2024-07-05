# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        criticals = []
        now = head
        ans = [-1, -1]
        loc = 1

        def check(node):
            if node.val < node.next.val and node.next.val > node.next.next.val:
                return True
            if node.val > node.next.val and node.next.val < node.next.next.val:
                return True
            return False

        minimum = int(1e9)
        while now and now.next and now.next.next:
            if check(now):
                if criticals:
                    minimum = min(minimum, loc - criticals[-1])
                criticals.append(loc)
            now = now.next
            loc += 1

        if len(criticals) < 2:
            return [-1, -1]

        ans[0] = minimum 
        ans[1] = criticals[-1] - criticals[0] 

        return ans
