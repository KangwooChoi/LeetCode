class Solution {
public:
    int numTilings(int n) {
        int MOD = 1'000'000'007;
        if (n <= 2) return n;
        long fCurr = 5L;
        long fPrev = 2L;
        long fBeforePrev = 1L;
        for (int k = 4; k < n + 1; k++) {
            long tmp = fPrev;
            fPrev = fCurr;
            fCurr = (2 * fCurr + fBeforePrev) % MOD;
            fBeforePrev = tmp;
        }
        return static_cast<int>(fCurr);
    }
};