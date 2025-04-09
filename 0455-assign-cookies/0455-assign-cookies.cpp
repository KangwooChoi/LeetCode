class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int> greedies;
        priority_queue<int> cookies;
        for (int greedy : g) {
            greedies.push(greedy);
        }
        for (int cookie : s) {
            cookies.push(cookie);
        }
        int ans = 0;
        while (!greedies.empty() && !cookies.empty()) {
            if (greedies.top() <= cookies.top()) {
                ans++;
                greedies.pop();
                cookies.pop();
            } else {
                greedies.pop();
            }
        }
        return ans;
    }
};