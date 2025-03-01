class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        vector<int> counter(n+1,0);
        for (int i = 0; i < n; i++) {
            if (data[i] == 1) counter[i+1] = counter[i] + 1;
            else counter[i+1] = counter[i];
        } 
        int k = counter[n];
        int left = 0;
        int ans = INT_MAX;
        for (int right = k; right < n + 1; right++) {
            ans = min(ans, k - counter[right] + counter[left++]);
        }
        return ans;
    }
};