class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        def check(matrix, dp, size):
            def check_(matrix, row, col, dp, size):
                if row+size > len(matrix):
                    dp[row][col] = 0
                    return False
                if col+size > len(matrix[0]):
                    dp[row][col] = 0
                    return False
                for r in range(row, row+size):
                    for c in range(col, col+size):
                        if matrix[r][c] == 0:
                            dp[row][col] = 0
                            return False
                return True

            cnt = 0
            for row in range(len(matrix)):
                for col in range(len(matrix[0])):
                    if dp[row][col] == 0:
                        continue
                    if check_(matrix, row, col, dp, size):
                        cnt += 1
                    else:
                        dp[row][col] = 0
            return cnt
        dp = copy.deepcopy(matrix)
        ans = 0
        for i in range(1, min(len(matrix), len(matrix[0]))+1):
            ans += check(matrix, dp, i)
            print(i, ans)
        return ans