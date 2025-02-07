class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                if (pq.size() < ladders) {
                    pq.push(diff);
                } else {
                    if (pq.empty() || pq.top() >= diff) {
                        bricks -= diff;
                    } else {
                        int poll = pq.top();
                        pq.pop();
                        pq.push(diff);
                        bricks -= poll;
                    }
                    if (bricks < 0) return i;
                }
            }
        } 
        return n - 1;
    }
};
//class Solution {
//public:
//    int ans = 0; 
//    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//        backtrack(heights, bricks, ladders, 0);
//        return ans;
//    }
//    void backtrack(vector<int>& h, int b, int l, int i) {
//        if (i == h.size() - 1) {
//            ans = i;
//            return;
//        }
//        if (h[i] >= h[i+1]) {
//            ans = max(ans, i+1);
//            backtrack(h, b, l, i+1); 
//            return;
//        } 
//        int diff = h[i+1] - h[i];
//        if (diff <= b) {
//            ans = max(ans, i+1);
//            backtrack(h, b-diff, l, i+1);
//        }
//        if (l > 0) {
//            ans = max(ans, i+1);
//            backtrack(h, b, l-1, i+1);
//        }
//        return;
//    }
//};