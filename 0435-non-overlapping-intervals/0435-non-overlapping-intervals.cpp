bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int ans = 0;
        int k = INT_MIN;

        for (int i = 0; i < intervals.size(); i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];

            if (x >= k) {
                k = y;
            } else {
                ans++;
            }
        } 
        return ans;
    }
};