class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        stack<pair<int,int>> st; 
        sort(meetings.begin(), meetings.end());
        for (auto meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            if (st.empty()) st.emplace(start,end);
            else {
                if (st.top().second >= start) {
                    st.top().second = max(st.top().second, end);
                } else {
                    st.emplace(start,end);
                }
            }
        }
        int ans = 0;
        int end = days;
        while (!st.empty()) {
            int preend = st.top().second;
            if (end - preend > 0) ans += end - preend;
            end = st.top().first - 1;
            st.pop();
        }
        ans += end;
        return ans;
    }
};