class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;    
        for (auto num: nums) {
            int cnt = 0;
            while (num > 0) {
                num /= 10;
                cnt++;
            }
            if (cnt % 2 == 0) ans++;
        }
        return ans;
    }
};