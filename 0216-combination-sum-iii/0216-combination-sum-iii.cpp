class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        makeCombi(0, v, k, n, ans);
        return ans;     
    }
private:
    void makeCombi(int start, vector<int> v, int k, int n, vector<vector<int>>& ans) {
        if(v.size() == k) {
            int sum = 0;
            for (auto v_ : v) sum += v_;
            if (sum == n) ans.push_back(v);
            return;
        } 
        for (int i = start + 1; i < 10; i++) {
            v.push_back(i);
            makeCombi(i, v, k, n, ans);
            v.pop_back();
        }
        return;
    }
};