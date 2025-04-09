class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int i = 0; i < k && i < nums.size(); i++) {
            if (++freq[nums[i]] >= 2) return true; 
        }   
        for (int i = k; i < nums.size(); i++) {
            if (++freq[nums[i]] >= 2) return true;
            freq[nums[i-k]]--;
        }
        return false;
    }
};