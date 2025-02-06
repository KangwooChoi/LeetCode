class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;
        vector<int> freq(n+1, 0);
        freq[A[0]]++;
        freq[B[0]]++;
        if (A[0] == B[0]) ans.push_back(1);
        else ans.push_back(0);
        for (int i = 1; i < n; i++) {
            int temp = ans.back();
            freq[A[i]]++;
            if (freq[A[i]] == 2) temp++;
            freq[B[i]]++;
            if (freq[B[i]] == 2) temp++;
            ans.push_back(temp);
        }
        return ans; 
    }
};