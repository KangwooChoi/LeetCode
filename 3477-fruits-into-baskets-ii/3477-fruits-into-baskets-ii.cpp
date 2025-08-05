class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<bool> occupied(n,false);
        for (int i = 0; i < n; i++) {
            int curr = fruits[i];
            for (int j = 0; j < n; j++) {
                if (occupied[j] == false && curr <= baskets[j]) {
                    occupied[j] = true;
                    break;
                }
            }
        }    
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (occupied[i] == false) ans++;
        }
        return ans;
    }
};