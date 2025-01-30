class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        int n = nums.size();
        for (int i = 0; i < n; i++){
            vector<int> intermediate;
            intermediate.push_back(nums[i]);
            backtrack(nums, i, intermediate, ans);
            intermediate.pop_back();
        }
        return ans;
    }
private:
    void backtrack(vector<int>& nums, int i, vector<int> temp, vector<vector<int>>& res) {
        res.push_back(temp);
        for (int j = i+1; j < nums.size(); j++) {
            temp.push_back(nums[j]); 
            backtrack(nums, j, temp, res);
            temp.pop_back();
        }
    }
};