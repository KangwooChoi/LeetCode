class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> bins;
        int rep = 1;
        while (n) {
            if (n % 2 == 1) {
                bins.push_back(rep);
            }
            n /= 2;
            rep *= 2;
        }

        int m = bins.size();
        vector<vector<int>> results(m, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            int cur = 1;
            for (int j = i; j < m; ++j) {
                cur = static_cast<long long>(cur) * bins[j] % mod;
                results[i][j] = cur;
            }
        }

        vector<int> ans;
        for (const auto& query : queries) {
            ans.push_back(results[query[0]][query[1]]);
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};
//class Solution {
//public:
//    vector<int> productQueries(int n, vector<vector<int>>& queries) {
//        int k = 1;
//        vector<int> powers;
//        while (n > 0) {
//            int remain = n % 2;
//            n /= 2;
//            if (remain) powers.push_back(k);
//            k *= 2;
//        } 
//        vector<long long> dp;
//        dp.push_back(1);
//        for (int i = 0; i < powers.size(); i++) {
//            dp.push_back(dp[i]*powers[i]);
//        }
//        vector<int> ans;
//        for (auto q : queries) {
//            int left = q[0], right = q[1];
//            long long intermediate = (dp[right+1] / dp[left]) % (long long)(1e9+7);
//            ans.push_back((int)intermediate);
//        }
//        return ans;
//    }
//};