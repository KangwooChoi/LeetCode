class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = piles[0], right = piles[piles.size()-1]; 
        
        while (left < right) {
            int mid = (left + right) / 2;
            int hourSpent = 0;
            for (int pile: piles) {
                hourSpent += pile / mid + (pile % mid != 0);
            }
            if (hourSpent <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right; 
    }
};