class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int left = 1, right = 0;
        for (int i = 0; i < ribbons.size(); i++) {
            right = max(right, ribbons[i]);
        }
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i = 0; i < ribbons.size(); i++) {
                cnt += ribbons[i] / mid;
            }
            if (cnt >= k) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans; 
    }
};