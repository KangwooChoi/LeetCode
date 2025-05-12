class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> uset;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = 0; k < n; k++) {
                    if (j == k || i == k) continue;
                    int temp = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (temp % 2 == 0) uset.insert(temp);
                }
            }
        }    
        vector<int> ans;
        for (int num : uset) {
            ans.push_back(num);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};