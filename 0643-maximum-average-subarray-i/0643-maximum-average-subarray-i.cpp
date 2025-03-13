class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ksum = 0;
        for (int i = 0; i < k; i++) {
            ksum += nums[i];
        }
        double ans = ksum / k;
        for (int i = k; i < nums.size(); i++) {
            ksum += nums[i] - nums[i-k];
            ans = max(ans, double(ksum / k));
        }       
        return ans;
    }
};