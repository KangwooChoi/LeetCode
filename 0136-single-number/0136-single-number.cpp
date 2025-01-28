class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int p = 0;
        while (p < nums.size()-1) {
            if (nums[p] != nums[p+1]) return nums[p];
            p += 2;
        }
        return nums[nums.size()-1]; 
    }
};