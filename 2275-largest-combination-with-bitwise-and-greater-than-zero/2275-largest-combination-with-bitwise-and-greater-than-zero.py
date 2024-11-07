class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        def counter(num, arr):
            i = 0
            while num:
                arr[i] += num % 2
                num //= 2
                i += 1
        bit_arr = [0] * 30
        for cand in candidates:
            counter(cand, bit_arr)
            #print(bit_arr) 
        return max(bit_arr)