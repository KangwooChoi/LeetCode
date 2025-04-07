class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        return helper(nums, 0, left, right);
    }
private:
    bool helper(vector<int>& nums, int index, vector<int> left, vector<int> right) {
        if (nums.size() == index) {
            if (sumHelper(left) == sumHelper(right)) return true;
            else return false;
        }
        left.push_back(nums[index]);
        bool leftRes = helper(nums, index+1, left, right);
        left.pop_back();
        right.push_back(nums[index]);
        bool rightRes = helper(nums, index+1, left, right);
        right.pop_back();
        return leftRes || rightRes;
    }
    int sumHelper(vector<int> list) {
        int res = 0;
        for (int i = 0; i < list.size(); i++) res += list[i];
        return res;
    }
};