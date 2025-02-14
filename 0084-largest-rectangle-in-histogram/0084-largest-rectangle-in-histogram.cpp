class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                int curr_h = heights[st.top()];
                st.pop();
                int curr_w = i - st.top() - 1;
                max_area = max(max_area, curr_h * curr_w);
            }
            st.push(i);
        } 
        while (st.top() != -1) {
            int curr_h = heights[st.top()];
            st.pop();
            int curr_w = heights.size() - st.top() - 1;
            max_area = max(max_area, curr_h * curr_w);
        }
        return max_area;
    }
};