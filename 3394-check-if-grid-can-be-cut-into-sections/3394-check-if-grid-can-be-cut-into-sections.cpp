class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        stack<pair<int,int>> st_x;
        stack<pair<int,int>> st_y;
        vector<vector<int>> rows;
        vector<vector<int>> cols;
        for (const auto& r : rectangles) {
            int xs = r[0], xe = r[2];
            int ys = r[1], ye = r[3];
            rows.push_back({xs,xe});
            cols.push_back({ys,ye});
        }
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        for (auto row : rows) {
            int xs = row[0], xe = row[1];
            if (st_x.empty()) {
                st_x.push({xs,xe});
            } else {
                if (st_x.top().second <= xs) {
                    st_x.push({xs,xe});
                } else {
                    st_x.top().second = max(st_x.top().second, xe);
                }
            }
        }
        for (auto col : cols) {
            int ys = col[0], ye = col[1];
            if (st_y.empty()) {
                st_y.push({ys,ye});
            } else {
                if (st_y.top().second <= ys) {
                    st_y.push({ys,ye});
                } else {
                    st_y.top().second = max(st_y.top().second, ye);
                }
            }

        }
        return st_x.size() >= 3 || st_y.size() >= 3;
    }
};