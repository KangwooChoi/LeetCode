class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> leftL(n,-1); 
        vector<int> leftR(n,-1); 
        vector<int> rightL(n,n);
        vector<int> rightR(n,n);
        for (int i = 0; i < n; i++) {
            char c = dominoes[i];
            if (c == '.') {
                leftL[i] = i >=1?leftL[i-1]:-1;
                leftR[i] = i >=1?leftR[i-1]:-1;
            }
            if (c == 'L') {
                leftL[i] = i;
                leftR[i] = i>=1?leftR[i-1]:-1;
            }
            if (c == 'R') {
                leftR[i] = i;
                leftL[i] = i>=1?leftL[i-1]:-1;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            char c = dominoes[i];
            if (c == '.') {
                rightL[i] = i < n-1 ? rightL[i+1]:n;
                rightR[i] = i < n-1 ? rightR[i+1]:n;
            }
            if (c == 'L') {
                rightL[i] = i;
                rightR[i] = i < n-1 ? rightR[i+1]:n;
            }
            if (c == 'R') {
                rightR[i] = i;
                rightL[i] = i < n-1 ? rightL[i+1] : n;
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            int leftDiff = leftR[i] - leftL[i] > 0 ? i - leftR[i] : n;
            int rightDiff = rightL[i] - rightR[i] < 0 ? rightL[i] - i : n;
            if (leftDiff == rightDiff) ans.push_back('.');
            else if (leftDiff > rightDiff) ans.push_back('L');
            else if (leftDiff < rightDiff) ans.push_back('R');
        }
        return ans;
    }
};