class Solution:
    def isHappy(self, n: int) -> bool:
        n_str = str(n)
        hash_set = set()
        while True:
            intermediate = 0
            for i in n_str:
                intermediate += int(i) * int(i)
            if intermediate == 1:
                return True
            if intermediate not in hash_set:
                hash_set.add(intermediate)
            else:
                return False
            n_str = str(intermediate)
            