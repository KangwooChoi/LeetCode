class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_num_set = set()
        ugly_num_set.add(1)
        curr_ugly = 1
        for i in range(n):
            curr_ugly = min(ugly_num_set)
            ugly_num_set.remove(curr_ugly)

            ugly_num_set.add(curr_ugly * 2)
            ugly_num_set.add(curr_ugly * 3)
            ugly_num_set.add(curr_ugly * 5)
        
        return curr_ugly