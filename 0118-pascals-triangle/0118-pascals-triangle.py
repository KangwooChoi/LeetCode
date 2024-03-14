class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        if numRows == 2:
            return [[1], [1,1]]
        ans = [[1], [1,1]]
        for i in range(3, numRows+1):
            row = [1]
            for j in range(i-2):
                row.append(ans[i-2][j]+ans[i-2][j+1])
            row.append(1)
            ans.append(row)
        return ans
            
            