class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            int curr_OR = arr[i];
            int prev_OR = 0;
            int j = i - 1;
            st.insert(curr_OR);
            while (j >= 0 && curr_OR != prev_OR)
            {
                curr_OR = curr_OR | arr[j];
                prev_OR = prev_OR | arr[j];
                st.insert(curr_OR);
                j--;
            }
        }
        return (int) st.size();
    }
};