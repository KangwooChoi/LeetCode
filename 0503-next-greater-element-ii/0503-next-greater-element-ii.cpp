class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // monotonic stack
        // brute-force 
        int n = nums.size();
        vector<int> ans(n,-1);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n+i+1; j++) {
                if (nums[i] < nums[j%n]) {
                    ans[i] = nums[j%n];
                    break;
                }
            }
        }
        return ans;
    }
};