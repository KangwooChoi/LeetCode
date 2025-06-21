class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freqs(26,0);
        for (char c : word) {
            freqs[c-'a']++;
        } 
        int ans = INT_MAX;
        for (int x : freqs) {
            int tmp = 0;
            for (int y : freqs) {
                if (x > y) tmp += y;
                if (y - k > x) tmp += y - k - x;
            }
            ans = min(ans, tmp);
        }
        return ans;
    }
};