class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            int dist = x*x + y*y; 
            pq.push({-dist,i});
        }
        vector<vector<int>> ans;
        while (k > 0) {
            auto [dist, index] = pq.top();
            ans.push_back(points[index]);
            pq.pop();
            k--;
        }
        return ans;
    }
};
//class Solution {
//public:
//    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//        priority_queue<pair<int,int>> pq;
//        for (int i = 0; i < points.size(); i++) {
//            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1]; 
//            pq.push({dist,i});
//            if (pq.size() > k) pq.pop();
//        }
//        vector<vector<int>> ans;
//        while (!pq.empty()) {
//            auto [dist, index] = pq.top();
//            ans.push_back(points[index]);
//            pq.pop();
//        }
//        return ans;
//    }
//};