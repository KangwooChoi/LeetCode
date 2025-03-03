class Solution {
public:
    unordered_map<int,vector<int>> valToIdx;
    vector<int> nums;

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            this->nums.push_back(nums[i]);
            valToIdx[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> targetGrp = valToIdx[target];
        int size = targetGrp.size();
        int idx = rand()%size;    
        return targetGrp[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */