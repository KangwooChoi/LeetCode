class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        sort(ranks.begin(), ranks.end());
        // long long left = 0, right = ranks[0] * cars * cars;
        long long left = 0, right = LLONG_MAX;
        while (left < right) {
            long long mid = (left + right) / 2;
            long long cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += sqrt(mid / (ranks[i]));
            }
            if (cnt >= cars) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};