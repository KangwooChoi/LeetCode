class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        connect = [0] * n
        for c1, c2 in roads:
            connect[c1] += 1
            connect[c2] += 1
        connect.sort(reverse=True)
        ans = 0
        for i in range(n):
            ans += connect[i] * (n - i) 
        return ans
