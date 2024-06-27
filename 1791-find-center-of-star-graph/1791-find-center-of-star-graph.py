class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        checker = defaultdict()
        for s, e in edges: 
            if s not in checker:
                checker[s] = 1
            else:
                return s
            if e not in checker:
                checker[e] = 1
            else:
                return e
        