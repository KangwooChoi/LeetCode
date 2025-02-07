class TicTacToe {
public:
    int n;

    vector<int> p1_row;
    vector<int> p1_col;
    vector<int> p1_diag;
    
    vector<int> p2_row;
    vector<int> p2_col;
    vector<int> p2_diag;

    TicTacToe(int n) {
        this->n = n;

        p1_row.assign(n,0);
        p1_col.assign(n,0);
        p1_diag.assign(2,0);
        
        p2_row.assign(n,0);
        p2_col.assign(n,0);
        p2_diag.assign(2,0);
        
    }
    
    int move(int row, int col, int player) {
        if (player == 1) {
            if (++p1_row[row] == n) return 1;
            if (++p1_col[col] == n) return 1;
            if (row == col) {
                if (++p1_diag[0] == n) return 1;
            }
            if (row+col == n-1) {
                if (++p1_diag[1] == n) return 1;
            }
        } else {
            if (++p2_row[row] == n) return 2;
            if (++p2_col[col] == n) return 2;
            if (row == col) {
                if (++p2_diag[0] == n) return 2;
            }
            if (row+col == n-1) {
                if (++p2_diag[1] == n) return 2;
            }
        }
        return 0; 
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */