class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); 
        vector<bool> seen(n+1,false);
        for (auto num : nums) {
            seen[num] = true;
        }
        for (int i = 0; i <= n; i++) {
            if (seen[i] == false) return i;
        }
        return -1;
    }
};