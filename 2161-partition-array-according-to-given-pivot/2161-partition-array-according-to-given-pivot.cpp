class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pivot > nums[i]) ans.push_back(nums[i]); 
            if (pivot == nums[i]) cnt++;
        }
        while (cnt > 0) {
            ans.push_back(pivot);
            cnt--;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (pivot < nums[i]) ans.push_back(nums[i]);
        }
        return ans;
    }
};