class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        num_cols = len(matrix[0])
        max_identical_rows = 0

        for curr_row in matrix:
            flipped_row = [1 - x for x in curr_row]
            identical_row_count = sum(
                1
                for compare_row in matrix
                if compare_row == curr_row or compare_row == flipped_row
            )

            max_identical_rows = max(max_identical_rows, identical_row_count)

        return max_identical_rows