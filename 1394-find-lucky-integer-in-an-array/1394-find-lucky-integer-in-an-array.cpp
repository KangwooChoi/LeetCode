class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> freq;
        for (int num : arr) {
            freq[num]++;
        } 
        int ans = -1;
        for (auto [n, f] : freq) {
            if (n == f) {
                ans = f;
            }
        }
        return ans;
    }
};