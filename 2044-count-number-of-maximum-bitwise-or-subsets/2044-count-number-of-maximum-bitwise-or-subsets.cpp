class Solution {
public:
    int ans = 0;

    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for (int num : nums) {
            target |= num;
        }    
        int curr = 0;
        cout << target << endl;
        backtrack(target, nums, 0, curr);
        return ans;
    }

    void backtrack(int target, vector<int>& nums, int pos, int curr) {
        if (pos == nums.size()) return;
        // non-select
        backtrack(target, nums, pos+1, curr); 
        // select
        if ((curr | nums[pos]) == target) {
            ans++;
        }
        backtrack(target, nums, pos+1, curr|nums[pos]); 
    }
};