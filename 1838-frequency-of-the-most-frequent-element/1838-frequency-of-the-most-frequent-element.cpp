class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int ans = 0;
        long curr = 0;
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;
            while ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
//class Solution {
//public:
//    int maxFrequency(vector<int>& nums, int k) {
//        int ans = 0;    
//        int n = nums.size();
//        sort(nums.rbegin(), nums.rend());
//        for (int i = 0; i < n-1; i++) {
//            int buffer = k;
//            int cnt = 1;
//            for (int j = i+1; j < n; j++) {
//                if (buffer > 0) {
//                    buffer -= nums[i] - nums[j];
//                    if (buffer >= 0) cnt++;
//                    ans = max(ans, cnt);
//                } else break;
//            }
//        }
//        return ans;
//    }
//};