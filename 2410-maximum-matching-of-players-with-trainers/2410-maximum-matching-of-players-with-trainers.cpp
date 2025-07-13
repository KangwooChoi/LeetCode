class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int> pq_pl;
        priority_queue<int> pq_tr; 
        for(auto p : players) {
            pq_pl.push(p); 
        }
        for(auto t : trainers) {
            pq_tr.push(t); 
        }
        int ans = 0;
        while (!pq_pl.empty() && !pq_tr.empty()) {
            if (pq_pl.top() <= pq_tr.top()) {
                pq_pl.pop();
                pq_tr.pop();
                ans++;
            } else {
                pq_pl.pop();
            }
        }
        return ans;
    }
};