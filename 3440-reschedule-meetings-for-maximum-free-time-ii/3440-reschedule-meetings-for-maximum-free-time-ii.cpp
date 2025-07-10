class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size(), res = 0;
        for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
            int left1 = i == 0 ? 0 : endTime[i - 1];
            int right1 = i == n - 1 ? eventTime : startTime[i + 1];
            if (endTime[i] - startTime[i] <= t1) {
                res = max(res, right1 - left1);
            }
            t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            res = max(res, right1 - left1 - (endTime[i] - startTime[i]));

            int left2 = i == n - 1 ? 0 : endTime[n - i - 2];
            int right2 = i == 0 ? eventTime : startTime[n - i];
            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
                res = max(res, right2 - left2);
            }
            t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) -
                             endTime[n - i - 1]);
        }
        return res;
    }
};
//class Solution {
//public:
//    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
//        int n = startTime.size();
//        vector<int> freetime;
//        vector<int> meeting;
//        freetime.push_back(startTime[0] - 0);
//        meeting.push_back(endTime[0] - startTime[0]);
//        for (int i = 1; i < n; i++) {
//            freetime.push_back(startTime[i] - endTime[i-1]);
//            meeting.push_back(endTime[i] - startTime[i]);
//        } 
//        freetime.push_back(eventTime - endTime[n-1]);
//        int ans = freetime[0]; 
//        for (int i = 0; i < freetime.size() - 1; i++) {
//            int free = freetime[i] + freetime[i+1] + meeting[i];
//            ans = max(ans, free);
//        }
//        return ans;
//    }
//};