class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        def bit_counter(num, arr):
            index = 0
            while num:
                arr[index] += num % 2
                num //= 2
                index += 1
        
        def find_max_k(arr):
            add = 1
            ans = 0
            for i in arr:
                if i % 2 == 0:
                    ans += add 
                add *= 2
            return ans

        ans = deque()
        arr = [0] * maximumBit
        for num in nums:
            bit_counter(num, arr)
            #print(arr)
            ret = find_max_k(arr)
            ans.appendleft(ret)

        return list(ans)