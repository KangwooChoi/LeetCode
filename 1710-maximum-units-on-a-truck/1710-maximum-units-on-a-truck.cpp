class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>> pq;
        for (auto curr : boxTypes) {
            pq.push({curr[1], curr[0]});
        }    
        int ans = 0;
        int cnt = 0;
        while (!pq.empty() && cnt < truckSize) {
            auto curr = pq.top();
            pq.pop();
            if (curr.second + cnt > truckSize) {
                ans += curr.first * (truckSize - cnt);
                return ans;
            } else {
                ans += curr.first * curr.second;
                cnt += curr.second;
            } 
        }
        return ans;
    }
};