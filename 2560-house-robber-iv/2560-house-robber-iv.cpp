class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int minReward = 1, maxReward = *max_element(nums.begin(), nums.end()), totalHouses = nums.size();
        while (minReward < maxReward) {
            int mid = (minReward + maxReward) / 2;
            int possibleThefts = 0;
            for (int index = 0; index < totalHouses; ++index) {
                if (nums[index] <= mid) {
                    possibleThefts += 1;
                    index++;
                }
            }
            if (possibleThefts >= k) maxReward = mid;
            else minReward = mid + 1;
        }
        return minReward;
    }
};
//class Solution {
//public:
//    int minCapability(vector<int>& nums, int k) {
//        int ans = INT_MAX;    
//        backtrack(nums, 0, false, k, 0, ans);
//        return ans;
//    }
//private:
//    void backtrack(vector<int>& nums, int idx, bool isPick, int k, int maximum, int& ans) {
//        if (k == 0) {
//            ans = min(ans, maximum); 
//            return; 
//        }
//        if (idx == nums.size()) return;
//        if (!isPick) backtrack(nums, idx+1, true, k-1, max(maximum, nums[idx]), ans);
//        backtrack(nums, idx+1, false, k, maximum, ans);
//        return;
//    }
//};