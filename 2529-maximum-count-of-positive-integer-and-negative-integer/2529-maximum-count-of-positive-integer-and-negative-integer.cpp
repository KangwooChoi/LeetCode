class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int isN = 0, isP = 0;    
        for (int num : nums) {
            if (num < 0) isN++;
            if (num > 0) isP++;
        }
        return max(isN, isP);
    }
};