class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxDay = 0;
        for (int i = 0; i < events.size(); i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<>> pq;
        sort(events.begin(), events.end());
        int ans = 0;
        for (int i = 0, j = 0; i <= maxDay; i++) {
            while (j < n && events[j][0] <= i) {
                pq.emplace(events[j][1]);
                j++;
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};
//class Solution {
//public:
//    int maxEvents(vector<vector<int>>& events) {
//        sort(events.begin(), events.end());
//        vector<int> avails;
//        avails.push_back(0);
//        for (auto event : events) {
//            int s = event[0], e = event[1];
//            int last = avails.back();
//            if (last < s) {
//                avails.push_back(s);
//            } else if (last < e) {
//                avails.push_back(last+1);
//            }
//        } 
//        return avails.size() - 1;
//    }
//};