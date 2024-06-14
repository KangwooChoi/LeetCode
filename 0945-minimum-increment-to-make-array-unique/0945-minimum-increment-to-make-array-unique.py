class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        from collections import Counter
        counter = Counter(nums)
        keys = sorted(counter.keys())
        n = len(keys)
        ans = 0
        overflow = 0
        for i, key in enumerate(keys):
            #print('key, overflow prev: ', key, overflow)
            overflow += counter[key] - 1
            if overflow >= 1:
                #print("key, overflow: ", key, overflow)
                next_val = key + 1
                while overflow:
                    #print("n, i: ", n, i)
                    if i == n - 1:
                        ans += (overflow + 1) * overflow // 2
                        return ans
                    ans += overflow
                    #print("i+1: ", i+1)
                    if next_val == keys[i+1]:
                        #print('overflow: ', overflow)
                        break
                    next_val = next_val + 1
                    overflow -= 1
        return ans
                    