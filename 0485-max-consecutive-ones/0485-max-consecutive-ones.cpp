class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, curr = 0;
        for (int num : nums) {
            if (num == 1) {
                curr++;
                if (curr > ans) ans = curr;
            } else {
                curr = 0;
            }
        } 
        return ans;
    }
};