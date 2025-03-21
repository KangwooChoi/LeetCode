class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int p = abs(nums[i]) - 1;
            if (nums[p] > 0) nums[p] = -nums[p];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
};