class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = i + 1; j < i + n; j++) {
                if (nums[(j-1)%n] > nums[j%n]) {
                    flag = false;
                    break; 
                }
            }
            if (flag) return true;
        }
        return false; 
    }
};