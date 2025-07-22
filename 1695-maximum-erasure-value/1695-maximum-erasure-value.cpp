class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, currSum = 0, left = 0;
        unordered_set<int> seen;
        for (int right = 0; right < nums.size(); right++) {
            while (seen.find(nums[right]) != seen.end()) {
                seen.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }
            currSum += nums[right];
            seen.insert(nums[right]);
            ans = max(ans, currSum);
        }
        return ans;
    }
};