class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        final_xor = 0
        for n in nums:
            final_xor = final_xor ^ n
        return bin(final_xor ^ k).count('1')
#class Solution:
#    def minOperations(self, nums: List[int], k: int) -> int:
#        def toBin(num):
#            cnt = 0
#            while num >= 1:
#                base[cnt] += num % 2
#                num //= 2
#                cnt += 1
#        
#        goal = defaultdict()
#        temp = k
#        cnt = 0
#        while temp >= 1:
#            goal[cnt] = temp % 2
#            temp //= 2
#            cnt += 1
#        #print("goal: ", goal)
#            
#        base = defaultdict(int)
#        for n in nums:
#            toBin(n)
#        #print("base: ", base)
#
#        if len(base) > len(goal):
#            for i in range(len(goal), len(base)):
#                goal[i] = 0
#        elif len(goal) > len(base):
#            for i in range(len(base), len(goal)):
#                base[i] = 0
#
#        ans = 0
#        for i in range(max(len(base), len(goal))):
#            if goal[i] == 0 and base[i] % 2 != 0:
#                ans += 1
#            elif goal[i] == 1 and  base[i] % 2 == 0:
#                ans += 1
#        return ans
#