class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.rbegin(), candidates.rend());
        vector<vector<int>> ans;
        int n = candidates.size();
        for (int i = 0; i < n; i++) {
            vector<int> result;
            int cand = candidates[i];
            result.push_back(cand);
            backtrack(candidates, i, target-cand, result, ans);
            result.pop_back();
        } 
        return ans;
    }
private:
    void backtrack(vector<int>& candidates, int index, int target, vector<int> res, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        if (target < 0) return;
        for (int i = index; i < candidates.size(); i++) {
            int cand = candidates[i];
            res.push_back(cand);
            backtrack(candidates, i, target-cand, res, ans);
            res.pop_back();
        }
        return;
    }
};