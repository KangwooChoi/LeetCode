class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1000000;
        while (left < right) {
            int mid = (left + right) / 2;
            int division = 0;
            for (int i = 0; i < nums.size(); i++) {
                division += nums[i] / mid;
                if (nums[i]%mid != 0) division++;  
                if (division > threshold) {
                    break;
                }
            }
            if (division > threshold) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right; 
    }
};