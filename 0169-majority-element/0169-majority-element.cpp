class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int half = nums.size() / 2; 
        if (nums.size() % 2 != 0) half++; 
        int contiguous = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] == nums[i]) contiguous++; 
            else contiguous = 1;
            if (contiguous >= half) return nums[i];
        }
        return -1;
    }
};