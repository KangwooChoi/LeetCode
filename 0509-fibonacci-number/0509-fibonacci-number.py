class Solution:
    def fib(self, n: int) -> int:
        #if n <= 1:
        #    return n
#
        #return self.fib(n-1) + self.fib(n-2) 

        # cached
        if n <= 1:
            return n
        cached = [0, 1]
        for i in range(2, n+1):
            cached.append(cached[i-1] + cached[i-2])
        return cached[n]