class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        vector<vector<int>> patterns = {{0,0}, {0,1}, {1,0}, {1,1}};
        for (auto& pattern : patterns) {
            int cnt = 0;
            for (int num : nums) {
                if (num%2 == pattern[cnt%2]) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};