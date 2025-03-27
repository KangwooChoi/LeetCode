class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int mostFreqNum = 0, mostCnt = 0;
        for (auto f : freq) {
            if (mostCnt < f.second) {
                mostFreqNum = f.first;
                mostCnt = f.second;
            }
        }
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mostFreqNum == nums[i]) cnt++;
            int remain = n-1-i;
            if (cnt > (i+1) / 2 && (mostCnt - cnt) > remain / 2) return i;
        }
        return -1;
    }
};