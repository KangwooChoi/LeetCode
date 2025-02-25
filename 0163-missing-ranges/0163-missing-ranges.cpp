class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) return {{lower, upper}};
        vector<vector<int>> ans;
        if (nums[0] != lower) {
            ans.push_back({lower, nums[0]-1});
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] + 1 != nums[i]) {
                ans.push_back({nums[i-1]+1, nums[i]-1});
            }
        }
        if (nums[nums.size()-1] != upper) {
            ans.push_back({nums[nums.size()-1]+1, upper});
        }
        return ans; 
    }
};