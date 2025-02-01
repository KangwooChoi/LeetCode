class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            um[nums[i]]++;
        }
        vector<int> ans;
        ans.push_back(um.size());
        for (int i = 1; i < n - k + 1; i++) {
            um[nums[i+k-1]]++;
            if(--um[nums[i-1]]==0) um.erase(nums[i-1]);
            ans.push_back(um.size());
        }
        return ans; 
    }
};