class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        ans += plus(nums, target, 0);
        ans += minus(nums, target, 0);
        return ans / 2;
    }
private:
    int plus(vector<int>& nums, int target, int index) {
        //cout << nums.size() << ": " << index << endl;
        if (index == nums.size()) {
            if (target == 0) return 1;
            else return 0;
        } 
        int ret = 0;
        ret += plus(nums, target - nums[index], index+1);
        ret += minus(nums, target - nums[index], index+1);
        return ret;
    }
    int minus(vector<int>& nums, int target, int index) {
        //cout << nums.size() << ": " << index << endl;
        if (index == nums.size()) {
            if (target == 0) return 1;
            else return 0;
        } 
        int ret = 0;
        ret += plus(nums, target + nums[index], index+1);
        ret += minus(nums, target + nums[index], index+1);
        return ret;
    }
};