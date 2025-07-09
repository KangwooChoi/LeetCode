class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        startTime.push_back(eventTime);
        vector<int> freetime;
        freetime.push_back(startTime[0]);
        for (int i = 0; i < n; i++) {
            freetime.push_back(startTime[i+1] - endTime[i]); 
        }
        int ans = 0;
        int diff = 0;
        for (int j = 0; j <= k; j++) {
            diff += freetime[j];
        }
        ans = diff;
        for (int j = k + 1; j <= n; j++) {
            diff += freetime[j] - freetime[j-k-1];
            ans = max(ans, diff);
        }
        return ans;
    }
};