class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr) 
        memo = [[0] * n for _ in range(n)]
        for i in range(n):
            memo[i][i] = arr[i]
            for j in range(i+1, n):
                memo[i][j] = memo[i][j-1] ^ arr[j]
        
        # 1 <= j < n
        ans = 0
        for j in range(1, n):
            for i in range(0, j):
                for k in range(j, n):
                    a = memo[i][j-1]
                    b = memo[j][k]
                    if a == b:
                        ans += 1
        return ans