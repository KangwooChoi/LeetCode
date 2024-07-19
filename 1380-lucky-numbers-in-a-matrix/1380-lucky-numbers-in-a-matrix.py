class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])
        cand = []
        ans = []
        for row in matrix: 
            cand.append(min(row))
        for col in range(n):
            temp = []
            for row in range(m):
                temp.append(matrix[row][col])
            if max(temp) in cand:
                ans.append(max(temp))
        return ans