class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (auto num : nums) {
            if (original < num) return original;
            if (original == num) original *= 2;
        } 
        return original;
    }
};