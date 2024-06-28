class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        mono_stack = [[temperatures[0], 0]]
        n = len(temperatures)
        ans = [0] * n 
        for i in range(1, n):
            while mono_stack and temperatures[i] > mono_stack[-1][0]:            
                _, k = mono_stack.pop()
                ans[k] = i - k
            mono_stack.append([temperatures[i], i])
        return ans
        #n = len(temperatures)
        #ans = [0] * n
        #mono_stack = [[0, temperatures[0]]]
        #for i in range(1, n):
        #    while mono_stack and temperatures[i] > mono_stack[-1][1]:
        #        k, _ = mono_stack.pop()
        #        ans[k] = i - k
        #    mono_stack.append([i, temperatures[i]])
        #return ans