class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int right = 0, left = 0;
        int curMin, curMax;
        long long windowLen = 0, total = 0;

        curMin = curMax = nums[right];

        for (right = 0; right < nums.size(); right++) {
            curMin = min(curMin, nums[right]);
            curMax = max(curMax, nums[right]);

            if (curMax - curMin > 2) {
                windowLen = right - left;
                total += (windowLen * (windowLen + 1) / 2);

                left = right;
                curMin = curMax = nums[right];

                while (left > 0 && abs(nums[right] - nums[left - 1]) <= 2) {
                    left--;
                    curMin = min(curMin, nums[left]);
                    curMax = max(curMax, nums[left]);
                }

                if (left < right) {
                    windowLen = right - left;
                    total -= (windowLen * (windowLen + 1) / 2);
                }
            }
        }
        windowLen = right - left;
        total += (windowLen * (windowLen + 1) / 2);

        return total; 
    }
};
//class Solution {
//public:
//    long long continuousSubarrays(vector<int>& nums) {
//        vector<pair<int, int>> valid_sub;
//        int minimum = nums[0];
//        int maximum = nums[0];
//        int left = 0;
//        int n = nums.size();
//        for (int right = 1; right < n; right++) {
//            maximum = max(maximum, nums[right]);
//            minimum = min(minimum, nums[right]);
//            if (maximum - minimum > 2) {
//                valid_sub.push_back(make_pair(left, right - 1));
//                maximum = nums[right];
//                minimum = nums[right];
//                left = right;
//            }
//        }
//        if (left != n - 1) {
//            valid_sub.push_back(make_pair(left, n - 1));
//        }
//        long long ans = 0;
//        for (auto left_right : valid_sub) {
//            int left = left_right.first;
//            int right = left_right.second;
//            cout << left << ", " << right << endl;
//            int step = right - left + 1;
//            ans += (step + 1) * step / 2; 
//        }
//        return ans;
//    }
//};