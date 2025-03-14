class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) nums[p++] = nums[i];
        }
        return p;
    }
};
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int p = 1;
//        for (int i = 1; i < nums.size(); i++) {
//            if (nums[i-1] == nums[i]) continue;
//            nums[p++] = nums[i];
//        }
//        return p; 
//    }
//};