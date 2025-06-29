class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i-1] * 2) % mod;
        }
        int ans = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans += power[right-left];
                ans %= mod;
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};
//class Solution {
//public:
//    int numSubseq(vector<int>& nums, int target) {
//        int ans = 0; 
//        sort(nums.begin(), nums.end());
//        vector<int> sub;
//        for (int i = 0; i < nums.size(); i++) {
//            sub.push_back(nums[i]);
//            backtrack(nums, target, sub, i+1, ans); 
//            sub.pop_back();
//        }
//        return ans;
//    }
//private:
//    void backtrack(vector<int>& nums, int target, vector<int> sub, int start, int& ans) {
//        if (sub[0] + sub[sub.size()-1] <= target) {
//            ans = (ans+1) % (1000000000 + 7);
//            for (int i = start; i < nums.size(); i++) {
//                sub.push_back(nums[i]);
//                backtrack(nums, target, sub, i+1, ans);
//                sub.pop_back();
//            }
//        } else {
//            return;
//        }
//    }
//};