class Solution {
public:
    int findDivisor(int num) {
        int ret = 0;
        int cnt = 0;
        for (int i = 2; i < num / 2 + 1; i++) {
            if (num % i == 0) {
                if (++cnt > 2) return 0;
                ret += i;
            }
        }
        return cnt == 2 ? ret + 1 + num : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (auto num : nums) {
            ans += findDivisor(num);
        }
        return ans;
    }
};