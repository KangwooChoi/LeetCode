class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> minimum(n, 0);
        vector<int> maximum(n, 10);
        int mini = 11;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]); 
            maximum[i] = maxi;
            mini = min(mini, arr[n-1-i]);
            minimum[n-1-i] = mini;
        }
        int ans = 1;
        for (int i = 0; i < n - 1; i++) {
            if (minimum[i+1] >= maximum[i]) ans++;
        }
        return ans > n ? n : ans;
    }
};