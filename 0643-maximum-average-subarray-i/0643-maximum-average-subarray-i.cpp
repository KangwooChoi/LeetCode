class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curr = 0;
        for (int i = 0; i < k; i++) {
            curr += nums[i];
        }
        double maximum = curr;
        for (int i = 0; i < nums.size() - k; i++) {
            curr = curr - nums[i] + nums[i+k];
            maximum = max(maximum, curr);
        }
        return maximum / k; 
    }
};