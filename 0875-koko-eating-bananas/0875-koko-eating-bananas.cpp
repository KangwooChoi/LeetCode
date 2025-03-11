class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int ans = left;
        while (left < right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int pile : piles) {
                cnt += pile / mid + (pile%mid == 0 ? 0 : 1);
            }
            if (cnt <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right; 
    }
};