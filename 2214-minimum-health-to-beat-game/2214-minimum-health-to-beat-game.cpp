class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long ans = 0;
        int maxDamage = 0;
        for (int i = 0; i < damage.size(); i++) {
            ans += damage[i];
            maxDamage = max(maxDamage, damage[i]);
        } 
        return ans - min(maxDamage, armor) + 1;
    }
};