class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        arr = [i for i in range(1, n+1)]
        while n > 1:
            q = k % n
            #print(q, arr)
            if q == 0:
                arr = arr[:-1]
            else:
                arr = arr[q:] + arr[:q-1]
            n -= 1
        return arr[0] 