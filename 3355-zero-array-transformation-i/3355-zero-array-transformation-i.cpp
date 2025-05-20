class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> increased(n+1,0);
        for (auto q : queries) {
            increased[q[0]]++;
            increased[q[1]+1]--;
        } 
        int add = 0;
        for (int i = 0; i < n; i++) {
            add += increased[i];
            if (add < nums[i]) return false;
        }
        return true;
    }
};