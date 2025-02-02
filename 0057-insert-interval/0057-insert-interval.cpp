class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> s;
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            if (s.empty()) {
                s.push(intervals[i]);
            } else {
                vector<int> curr = s.top();
                if (intervals[i][0] > curr[1]) {
                    ans.push_back(curr);
                    s.pop();
                    s.push(intervals[i]);
                } else if (curr[1] < intervals[i][1]){
                    s.top()[1] = intervals[i][1];
                }
            } 
        }
        if (!s.empty()) {
            ans.push_back(s.top());
        }
        return ans;
    }
};