# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def retStr(lnode: ListNode) -> str:
            if lnode.next is None:
                return str(lnode.val)
            return retStr(lnode.next)+str(lnode.val)

        def createLnode(l: str) -> ListNode:
            if len(l) == 1:
                return ListNode(int(l), None)
            else:
                return ListNode(int(l[-1]), createLnode(l[:-1]))

        l1_int = int(retStr(l1))
        l2_int = int(retStr(l2))
        ans_str = str(l1_int + l2_int)

        return createLnode(ans_str)
