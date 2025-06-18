class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i+2] - nums[i] > k) return {};
            ans.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return ans;
    }
};
//class Solution {
//public:
//    vector<vector<int>> divideArray(vector<int>& nums, int k) {
//        vector<vector<int>> ans;        
//        sort(nums.begin(), nums.end());
//        int left = 0;
//        for (int right = 0; right < nums.size();) {
//            if (right - left == 2) {
//                if (nums[right] - nums[left] <= k) {
//                    ans.push_back({nums[left], nums[left+1], nums[left+2]});
//                    left = right+1;
//                    right++;
//                } else {
//                    left++;
//                    right++;
//                }
//            } else {
//                right++;
//            }
//        }
//        return ans;
//    }
//};