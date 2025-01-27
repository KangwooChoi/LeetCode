class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        vector<int> freq(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        int left = 0;
        while (left < nums.size()) {
            if (check(freq)) return ans;
            int n = nums.size();
            for (int right = left; right < min(left+3, n); right++) {
                freq[nums[right]]--;
            }
            left += 3;
            ans += 1;
        } 
        return ans;
    }

    bool check(vector<int>& f) {
        for (int i = 1; i < f.size(); i++) {
            if (f[i] > 1) return false;
        }
        return true;
    }
};