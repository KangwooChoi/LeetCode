class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> freq;
        int max_freq = 0;
        for (int i = 1; i <= n; i++) {
            int res = helper(i);
            freq[res]++;
            if (freq[res] > max_freq) max_freq = freq[res];
        }
        int ans = 0;
        for (auto f : freq) {
            if (f.second == max_freq) ans++;
        }
        return ans;
    }
private:
    int helper(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10; 
        }
        return res;
    }
};