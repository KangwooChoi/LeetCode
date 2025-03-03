class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<pair<int,int>> st;
        vector<int> ans;
        for (int i = 0; i < heights.size(); i++) {
            if (st.empty()) {
                st.push({heights[i], i});
            } else {
                while (!st.empty() && st.top().first <= heights[i]) {
                    st.pop();
                }
                st.push({heights[i], i});
            } 
        } 
        while (!st.empty()) {
            ans.push_back(st.top().second);
            st.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};