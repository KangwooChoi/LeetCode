class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int> g_pq;
        priority_queue<int> s_pq;
        for (int size : g) {
            g_pq.push(size);
        }
        for (int size : s) {
            s_pq.push(size);
        }
        int ans = 0; 
        while (!g_pq.empty() && !s_pq.empty()) {
            if (g_pq.top() <= s_pq.top()) {
                g_pq.pop();
                s_pq.pop();
                ans++;
            } else {
                g_pq.pop();
            }
        }
        return ans;
    }
};