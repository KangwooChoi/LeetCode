class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        int ans = 0;
        while (n > 1) {
            for (int i = 2; i < 1000; i++) {
                if (n % i == 0) {
                    ans += i;
                    n /= i;
                    break;
                }
            }

        }

        return ans;
    }
};