# Definition for polynomial singly-linked list.
# class PolyNode:
#     def __init__(self, x=0, y=0, next=None):
#         self.coefficient = x
#         self.power = y
#         self.next = next

class Solution:
    def helper(self, diction: 'defaultdict', poly: 'PolyNode'):
        next = poly
        while next:
            diction[next.power] += next.coefficient
            next = next.next
        return

    def builder(self, diction: 'defaultdict') -> 'PolyNode':
        keys = sorted(diction.keys(), reverse=True)
        root = PolyNode()
        prev = root
        for power in keys:
            coeff = diction[power]
            if coeff != 0:
                now = PolyNode(coeff, power)
                prev.next = now
                prev = now

        return root.next  

    def addPoly(self, poly1: 'PolyNode', poly2: 'PolyNode') -> 'PolyNode':
        power_coeff = defaultdict(int)
        self.helper(power_coeff, poly1) 
        self.helper(power_coeff, poly2) 
        return self.builder(power_coeff)