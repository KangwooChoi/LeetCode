class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> freq(n,0);
        vector<int> perm;
        for (int i = 0; i < n; i++) {
            perm.push_back(nums[i]);
            freq[i]++;
            backtrack(nums, perm, freq, ans);
            perm.pop_back();
            freq[i]--;
        }
        return ans;
    }
private:
    void backtrack(vector<int>& nums, vector<int> p, vector<int> f, vector<vector<int>>& res) {
        if (p.size() == nums.size()) {
            res.push_back(p);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (f[i] >= 1) continue;
            p.push_back(nums[i]);
            f[i]++;
            backtrack(nums, p, f, res);
            p.pop_back();
            f[i]--;
        }
    }
};