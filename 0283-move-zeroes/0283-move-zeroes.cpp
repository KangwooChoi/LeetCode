class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) swap(nums[p++], nums[i]);
        }
    }
};
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int p = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] != 0) swap(nums[i], nums[p++]);    
//        }
//    }
//};
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//        int p = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] != 0) nums[p++] = nums[i];
//        }
//        while (p < nums.size()) {
//            nums[p++] = 0;
//        }
//    }
//};