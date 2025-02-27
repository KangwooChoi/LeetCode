class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int prevMinIdx = 0;
        int prevNum = nums[0] * nums[0];
        for (int i = 0; i < n; i++) {
            nums[i] *= nums[i];
            if (prevNum > nums[i]) {
                prevMinIdx = i;
                prevNum = nums[i];
            }
        }
        int left = prevMinIdx-1, right = prevMinIdx+1; 
        vector<int> ans;
        ans.push_back(prevNum);
        while (left >= 0 && right < n) {
            if (nums[left] < nums[right]) {
                ans.push_back(nums[left--]);
            } else if (nums[left] > nums[right]) {
                ans.push_back(nums[right++]);
            } else if (nums[left] == nums[right]) {
                ans.push_back(nums[left--]);
                ans.push_back(nums[right++]);
            }
        }
        while (left >= 0) {
            ans.push_back(nums[left--]);
        }
        while (right < n) {
            ans.push_back(nums[right++]);
        }
        return ans;
    }
};