class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sums;
        sums.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            sums.push_back(nums[i] + sums.back()); 
        } 
        int total = sums.back();
        for (int i = 0; i < nums.size(); i++) {
            if (sums[i] * 2 == total - nums[i]) return i; 
        }
        return -1;
    }
};