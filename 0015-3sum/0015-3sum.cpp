class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n-2; i++) {
            if (i==0 || nums[i] != nums[i-1]) {
                twoSum(nums, i, ans);
            }
        }
        return ans;
    }
private:
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& res) {
        int lo = i+1, hi = nums.size()-1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum == 0) {
                res.push_back({nums[i],nums[lo++], nums[hi--]});
                while (lo < hi && nums[lo] == nums[lo-1]) lo++;
            } else if (sum < 0) {
                lo++;
            } else {
                hi--;
            }
        }
    }
};
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> ans;
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        for (int i = 0; i < n-2; i++) {
//            if (i==0 || nums[i] != nums[i-1]) {
//                twoSum(nums, i, ans);
//            }
//        }
//        return ans; 
//    }
//private:
//    void twoSum(vector<int>& nums, int i, vector<vector<int>>& res) {
//        int lo = i+1, hi = nums.size()-1;
//        while (lo < hi) {
//            int sum = nums[i] + nums[lo] + nums[hi];
//            if (sum < 0) {
//                lo++;
//            } else if (sum > 0) {
//                hi--;
//            } else {
//                res.push_back({nums[i], nums[lo++], nums[hi--]});
//                while (lo < hi && nums[lo] == nums[lo-1]) lo++;
//            }
//        }
//    }
//};