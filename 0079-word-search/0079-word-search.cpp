class Solution {
private:
    vector<vector<char>> board;
    int ROWS;
    int COLS;

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        ROWS = board.size();
        COLS = board[0].size();
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                if (backtrack(row, col, word, 0)) return true;
        return false;
    }

protected:
    bool backtrack(int row, int col, const string& word, int index) {
        /* Step 1). check the bottom case. */
        if (index >= word.size()) return true;
        /* Step 2). Check the boundaries. */
        if (row < 0 || row == ROWS || col < 0 || col == COLS ||
            board[row][col] != word[index])
            return false;
        /* Step 3). explore the neighbors in DFS */
        // mark the path before the next exploration
        char temp = board[row][col];
        board[row][col] = '#';
        int rowOffsets[4] = {0, 1, 0, -1};
        int colOffsets[4] = {1, 0, -1, 0};
        for (int d = 0; d < 4; ++d) {
            if (backtrack(row + rowOffsets[d], col + colOffsets[d], word,
                          index + 1)) {
                // return without cleanup
                return true;
            }
        }
        /* Step 4). clean up and return the result. */
        board[row][col] = temp;
        return false;
    }
};
//class Solution {
//public:
//    vector<int> dx = {1, -1, 0, 0};
//    vector<int> dy = {0, 0, 1, -1};
//    int m, n;
//
//    bool exist(vector<vector<char>>& board, string word) {
//        m = board.size(); 
//        n = board[0].size();
//        vector<vector<bool>> visited(m, vector<bool>(n,false));
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                bool ret = checkNext(board, word, 0, i, j, visited); 
//                if (ret) return true;
//            }
//        }
//        return false;
//    }
//    
//    bool checkNext(vector<vector<char>>& board, string word, int index, int x, int y, vector<vector<bool>> visited) {
//        if (checkValid(x, y) == false || visited[x][y] == true) return false;
//        visited[x][y] = true;
//        if (word[index++] == board[x][y]) {
//            if (index == word.size()) return true;
//            for (int i = 0; i < 4; i++) {
//                int nx = x + dx[i];
//                int ny = y + dy[i];
//                bool ret = checkNext(board, word, index, nx, ny, visited);
//                if (ret) return true;
//            }
//        } 
//        return false;
//         
//    }
//
//    bool checkValid(int x, int y) {
//        return 0 <= x && x < m && 0 <= y && y < n; 
//    }
//};