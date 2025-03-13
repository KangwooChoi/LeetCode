class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                for (int j = 1; j < nums.size(); j++) {
                    if (nums[j-1] < nums[j]) return false;
                }
                break;
            };
        }
        return true;
    }
};