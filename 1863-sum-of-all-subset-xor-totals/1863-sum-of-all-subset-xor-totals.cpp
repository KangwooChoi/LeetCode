class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return XORSum(nums, 0, 0);    
    }
private:
    int XORSum(vector<int>& nums, int index, int currSum) {
        if (index == nums.size()) return currSum;

        int withCurrent = XORSum(nums, index+1, currSum^nums[index]);
        int withoutCurrent = XORSum(nums, index+1, currSum);

        return withCurrent + withoutCurrent;
    }
};