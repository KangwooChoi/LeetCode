class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        for (int i = 1; i < n; i++) {
            if (complexity[0] >= complexity[i]) return 0;
        }
        
        int mod = 1e9 + 7;
        int ans = 1;
        for (int i = 2; i < n; i++) {
            ans = static_cast<long long>(ans) * i % mod; 
        }
        return ans; 
    }
};