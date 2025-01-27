class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<double> sums;
        sums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            sums.push_back(nums[i]+sums[sums.size()-1]);
        }
        double ans = sums[k-1] / k;
        for (int i = k; i < nums.size(); i++) {
            ans = max(ans , (sums[i]-sums[i-k])/k); 
        }
        return ans;
        //double curr = 0;
        //for (int i = 0; i < k; i++) {
        //    curr += nums[i];
        //}
        //double maximum = curr;
        //for (int i = 0; i < nums.size() - k; i++) {
        //    curr = curr - nums[i] + nums[i+k];
        //    maximum = max(maximum, curr);
        //}
        //return maximum / k; 
    }
};