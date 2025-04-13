class Solution {
public:
    int countGoodNumbers(long long n) {
        static constexpr int mod = 1e9+7;
        auto quickmul = [](int x, long long y) -> int {
            int ret = 1, mul = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    ret = (long long)ret * mul % mod;
                }
                mul = (long long)mul * mul % mod;
                y /= 2;
            }
            return ret;
        };
        return (long long)quickmul(5, (n+1)/2) * quickmul(4, n/2) % mod;
    }
};
//class Solution {
//public:
//    int countGoodNumbers(long long n) {
//        long long mod = 10e9 + 7; 
//        int nprime = n / 2;
//        long long left = solve(5, nprime)%mod;
//        long long right = solve(4, nprime)%mod;
//        long long remain = (n%2) ? 5 : 1;
//        return (long long)((left%mod*right%mod)%mod*remain)%mod;
//    }
//private:
//    long long solve(int x, int p) {
//        return pow(x,p);
//    }
//};