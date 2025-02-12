class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int,greater<int>> map;
        for (int i = 0; i < k; i++) {
            map[nums[i]]++;
        }    
        vector<int> ans;
        ans.push_back(map.begin()->first);
        for (int i = k; i < nums.size(); i++) {
            if(--map[nums[i-k]] == 0) map.erase(nums[i-k]);
            map[nums[i]]++;
            ans.push_back(map.begin()->first);
        }
        return ans;
    }
};