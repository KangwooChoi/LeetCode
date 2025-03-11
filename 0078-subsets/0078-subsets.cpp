class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;    
        helper(nums, {}, 0, ans);
        return ans;
    }
private:
    void helper(vector<int> nums, vector<int> res, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(res);
            return;
        }
        helper(nums, res, idx+1, ans); 
        res.push_back(nums[idx]);
        helper(nums, res, idx+1, ans);
    }
};