class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> m;
        for (int i = 0; i < k; i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            } else {
                m[nums[i]]++;
            }
        }
        ans.push_back(m.size());
        for (int i = k; i < nums.size(); i++){
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1; 
            } else {
                m[nums[i]]++;
            }
            m[nums[i-k]]--;
            if (m[nums[i-k]] == 0) m.erase(nums[i-k]);
            ans.push_back(m.size());
        }
        return ans;
    }
};