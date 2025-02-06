class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for (int i = 0; i < intervals.size(); i++) {
            mp[intervals[i][0]]++;
            mp[intervals[i][1]]--;
        }    
        int cnt = 0, ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            cnt += it->second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};