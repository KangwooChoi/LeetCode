class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        for i in range(rows//2):
            for j in range(i, rows-i-1):
                temp0 = matrix[i][j]
                temp1 = matrix[j][rows-i-1]
                temp2 = matrix[rows-i-1][rows-j-1]
                temp3 = matrix[rows-j-1][i]

                matrix[j][rows-i-1] = temp0
                matrix[rows-i-1][rows-j-1] = temp1
                matrix[rows-j-1][i] = temp2
                matrix[i][j] = temp3