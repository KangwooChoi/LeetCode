class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (auto interval : intervals) {
            if (ans.empty()) ans.push_back(interval);
            else {
                if (ans.back()[1] >= interval[0]) {
                    ans.back()[1] = interval[1];
                } else {
                    ans.push_back(interval);
                }
            }
        }
        return ans;
    }
};
//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> ans;
//        sort(intervals.begin(), intervals.end());
//        for (auto interval : intervals) {
//            if (ans.empty()) {
//                ans.push_back(interval);
//                continue;
//            }
//            if (ans.back()[1] < interval[0]) {
//                ans.push_back(interval);
//                continue;
//            }
//            if (interval[0] <= ans.back()[1] && ans.back()[1] < interval[1]) {
//                ans.back()[1] = interval[1];
//            }
//        }
//        return ans;
//    }
//};